#include "EasyHandleBuilder.hpp"

#include <array>
#include <algorithm>
#include <exception>
#include <sstream>

#include <curl/curl.h>

#include "EasyHandle.hpp"
#include "EasyOptionsToCurl.hpp"

namespace CurlWrapper
{

struct Impl
{
    std::unique_ptr<EasyHandle> handle;
};

EasyHandleBuilder::EasyHandleBuilder()
    : m_impl(std::make_unique<Impl>())
{
    m_impl->handle = std::make_unique<EasyHandle>();
}

EasyHandleBuilder::~EasyHandleBuilder() = default;

std::unique_ptr<EasyHandle> EasyHandleBuilder::build() noexcept
{
    auto res = std::move(m_impl->handle);
    m_impl->handle = std::make_unique<EasyHandle>();

    return res;
}

void failSetOption(const EasyOption opt)
{
    std::stringstream ss;

    ss << "Failed to set option ";
    ss << static_cast<int>(opt);

    throw std::runtime_error(ss.str());
}

EasyHandleBuilder& EasyHandleBuilder::addOptionVoidPtr(
    const EasyOption opt,
    void* param)
{
    CURL* curl_handle = m_impl->handle->getHandle();

    auto res = curl_easy_setopt(curl_handle, convertOptToCurl(opt), param);

    if (res != CURLE_OK)
    {
        failSetOption(opt);
    }

    return *this;
}

EasyHandleBuilder& EasyHandleBuilder::addOptionString(
    const EasyOption opt,
    const std::string& param)
{
    CURL* curl_handle = m_impl->handle->getHandle();

    auto res = curl_easy_setopt(curl_handle, convertOptToCurl(opt), param.c_str());

    if (res != CURLE_OK)
    {
        failSetOption(opt);
    }

    return *this;
}

EasyHandleBuilder& EasyHandleBuilder::addOptionSList(
    const EasyOption /*opt*/,
    SList* /*param*/)
{
    //CURL* curl_handle = static_cast<CURL*>(m_impl->handle->getHandle());

    //@TODO: convert param to "curl_slist*"
    //curl_easy_setopt(curl_handle, convertOptToCurl(opt), param);

    return *this;
}

} // namespace CurlWrapper
