#include "MultiHandle.hpp"

#include <unordered_set>
#include <stdexcept>

#include <curl/curl.h>

#include "MultiCodesFromCurl.hpp"

namespace CurlWrapper
{

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

public:
    CURLM* handle;
    std::unordered_set<std::shared_ptr<EasyHandle>> easy_handles;
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
    CURLM* curl_multi_handle = getHandle();
    CURL* curl_easy_handle = easy_handle->getHandle();

    auto curl_res = curl_multi_add_handle(curl_multi_handle, curl_easy_handle);

    return convertMultiCodeToCurl(curl_res);
}

MultiCode MultiHandle::removeEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept
{
    CURLM* curl_multi_handle = getHandle();
    CURL* curl_easy_handle = easy_handle->getHandle();

    auto curl_res = curl_multi_remove_handle(curl_multi_handle, curl_easy_handle);

    return convertMultiCodeToCurl(curl_res);
}


} // namespace CurlWrapper
