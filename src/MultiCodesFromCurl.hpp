#pragma once

#include <array>

#include <curl/curl.h>

#include "MultiCodes.hpp"

namespace CurlWrapper
{
namespace MultiCodesFromCurl
{

static constexpr std::array s_conv_table
{
    std::pair(CURLM_CALL_MULTI_PERFORM, MultiCode::CALL_MULTI_PERFORM ),
    std::pair(CURLM_OK, MultiCode::OK ),
    std::pair(CURLM_BAD_HANDLE, MultiCode::BAD_HANDLE ),
    std::pair(CURLM_BAD_EASY_HANDLE, MultiCode::BAD_EASY_HANDLE ),
    std::pair(CURLM_OUT_OF_MEMORY, MultiCode::OUT_OF_MEMORY ),
    std::pair(CURLM_INTERNAL_ERROR, MultiCode::INTERNAL_ERROR ),
    std::pair(CURLM_BAD_SOCKET, MultiCode::BAD_SOCKET ),
    std::pair(CURLM_UNKNOWN_OPTION, MultiCode::UNKNOWN_OPTION ),
    std::pair(CURLM_ADDED_ALREADY, MultiCode::ADDED_ALREADY ),
    std::pair(CURLM_RECURSIVE_API_CALL, MultiCode::RECURSIVE_API_CALL ),
    std::pair(CURLM_WAKEUP_FAILURE, MultiCode::WAKEUP_FAILURE ),
    std::pair(CURLM_BAD_FUNCTION_ARGUMENT, MultiCode::BAD_FUNCTION_ARGUMENT ),
    std::pair(CURLM_ABORTED_BY_CALLBACK, MultiCode::ABORTED_BY_CALLBACK ),
    std::pair(CURLM_UNRECOVERABLE_POLL, MultiCode::UNRECOVERABLE_POLL ),
    std::pair(CURLM_LAST, MultiCode::LAST )
};

} // namespace MultiCodesFromCurl

constexpr MultiCode convertMultiCodeToCurl(const CURLMcode src) 
{
    for (auto pair : MultiCodesFromCurl::s_conv_table)
    {
        if (std::get<0>(pair) == src)
        {
            return std::get<1>(pair);
        }
    }

    return MultiCode::LAST;
}

} // namespace CurlWrapper
