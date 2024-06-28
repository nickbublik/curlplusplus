#pragma once

#include "EasyHandle.hpp"

namespace CurlWrapper
{

struct Message 
{
    bool completed;
    std::shared_ptr<EasyHandle> easy_handle;

    union {
        void *whatever;    /* message-specific data */
        CURLcode result;   /* return code for transfer */
    } data;
};

} // namespace CurlWrapper
