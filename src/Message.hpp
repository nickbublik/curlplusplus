#pragma once

#include "EasyHandle.hpp"
#include "EasyCodes.hpp"

namespace CurlWrapper
{

struct Message 
{
    bool completed;
    std::shared_ptr<EasyHandle> easy_handle;

    union {
        void *whatever;    /* message-specific data */
        EasyCode result;   /* return code for transfer */
    } data;
};

} // namespace CurlWrapper
