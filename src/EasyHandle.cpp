#include "EasyHandle.hpp"

#include <curl/curl.h>

namespace CurlWrapper
{

struct Impl
{
    Impl()
    {
        handle = curl_easy_init();
    }

    ~Impl()
    {
        curl_easy_cleanup(handle);
    }

public:
    CURL* handle;
};

EasyHandle::EasyHandle()
    : m_impl(std::make_unique<Impl>())
{
}

EasyHandle::~EasyHandle()
{
}

void* EasyHandle::getHandle() noexcept
{
    return m_impl->handle;
}

} // namespace CurlWrapper
