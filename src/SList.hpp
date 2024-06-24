#pragma once

namespace CurlWrapper
{

struct SList
{
    char* data;
    struct SList* next;
};

} // namespace CurlWrapper
