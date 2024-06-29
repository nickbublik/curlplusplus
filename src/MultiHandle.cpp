#include "MultiHandle.hpp"

#include <set>
#include <type_traits>
#include <stdexcept>

#include <curl/curl.h>

#include "MultiCodesFromCurl.hpp"
#include "EasyCodesFromCurl.hpp"

namespace CurlWrapper
{

struct EasyHandleComparator
{
    using is_transparent = std::true_type;

    bool operator()(const std::shared_ptr<EasyHandle>& lhs,
                    const std::shared_ptr<EasyHandle>& rhs) const
    {
        return lhs->getHandle() < rhs->getHandle();
    }

    bool operator()(const std::shared_ptr<EasyHandle>& lhs,
                    void* rhs) const
    {
        return lhs->getHandle() < rhs;
    }

    bool operator()(void* lhs,
                    const std::shared_ptr<EasyHandle>& rhs) const
    {
        return lhs < rhs->getHandle();
    }

};

struct Impl
{
    Impl()
    {
        handle = curl_multi_init();

        if (!handle)
        {
            throw std::runtime_error("Failed to create curl multi handle");
        }
    }

    ~Impl()
    {
        for (std::shared_ptr<EasyHandle> easy_handle : easy_handles)
        {
            CURL* curl_easy_handle = easy_handle->getHandle();
            curl_multi_remove_handle(handle, curl_easy_handle);
        }

        curl_multi_cleanup(handle);
    }

    MultiCode addEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept
    {
        if (easy_handles.find(easy_handle) != easy_handles.end())
        {
            return MultiCode::ADDED_ALREADY;
        }

        easy_handles.insert(easy_handle);

        auto curl_res = curl_multi_add_handle(handle, easy_handle->getHandle());
    
        return convertMultiCodeFromCurl(curl_res);
    }
    
    MultiCode removeEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept
    {
        if (easy_handles.find(easy_handle) == easy_handles.end())
        {
            return MultiCode::BAD_HANDLE;
        }

        auto curl_res = curl_multi_remove_handle(handle, easy_handle->getHandle());

        easy_handles.erase(easy_handle);
    
        return convertMultiCodeFromCurl(curl_res);
    }

    //Message convertFromCurlMessage(CURLMsg& curl_msg)
    //{
    //    //struct CURLMsg {
    //    //  CURLMSG msg;       /* what this message means */
    //    //  CURL *easy_handle; /* the handle it concerns */
    //    //  union {
    //    //    void *whatever;    /* message-specific data */
    //    //    CURLcode result;   /* return code for transfer */
    //    //  } data;
    //    //};

    //    //struct Message 
    //    //{
    //    //    bool completed;
    //    //    std::shared_ptr<EasyHandle> easy_handle;
    //    //
    //    //    union {
    //    //        void *whatever;    /* message-specific data */
    //    //        EasyCode result;   /* return code for transfer */
    //    //    } data;
    //    //};

    //    Message res;

    //    res.completed = curl_msg.result == CURLMSG_DONE;
    //    res.whatever = curl_msg.whatever;
    //}

    std::pair<Message, unsigned> info_read() noexcept
    {
        int messages_left = 0;
        CURLMsg* curl_msg = curl_multi_info_read(handle, &messages_left);

        Message message { false, nullptr, nullptr };

        if (curl_msg == nullptr)
        {
            message.completed = true;
            return { message, 0 };
        }

        auto it = easy_handles.find(curl_msg->easy_handle);

        if (it == easy_handles.end())
        {
            message.completed = false;
            message.data.result = EasyCode::READ_ERROR;
            return { message, static_cast<unsigned>(messages_left) };
        }

        message.completed = curl_msg->msg == CURLMSG_DONE;
        message.easy_handle = *it;
        message.data.whatever = curl_msg->data.whatever;
        message.data.result = convertEasyCodeFromCurl(curl_msg->data.result);

        return { message, static_cast<unsigned>(messages_left) };
    }

public:
    CURLM* handle;
    std::set<std::shared_ptr<EasyHandle>, EasyHandleComparator> easy_handles;
};

MultiHandle::MultiHandle()
    : m_impl(std::make_unique<Impl>())
{
}

MultiHandle::~MultiHandle()
{
}

void* MultiHandle::getHandle() noexcept
{
    return m_impl->handle;
}

MultiCode MultiHandle::addEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept
{
    return m_impl->addEasyHandle(easy_handle);
}

MultiCode MultiHandle::removeEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept
{
    return m_impl->removeEasyHandle(easy_handle);
}

std::pair<MultiCode, unsigned> MultiHandle::perform() noexcept
{
    CURLM* curl_multi_handle = getHandle();
    int running_easy_handles = 0;

    auto curl_res = curl_multi_perform(curl_multi_handle, &running_easy_handles);

    return { convertMultiCodeFromCurl(curl_res), running_easy_handles };
}

MultiCode MultiHandle::poll(const std::chrono::milliseconds& timeout) noexcept
{
    auto curl_res = curl_multi_poll(
            getHandle(),
            nullptr,
            0,
            static_cast<int>(timeout.count()),
            nullptr);

    return convertMultiCodeFromCurl(curl_res);
}

std::pair<Message, unsigned> MultiHandle::info_read() noexcept
{
    return m_impl->info_read();
}

} // namespace CurlWrapper
