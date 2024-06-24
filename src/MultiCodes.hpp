#pragma once

namespace CurlWrapper
{

enum class MultiCode
{
    CALL_MULTI_PERFORM = -1,
    OK,
    BAD_HANDLE,
    BAD_EASY_HANDLE,
    OUT_OF_MEMORY,
    INTERNAL_ERROR,
    BAD_SOCKET,
    UNKNOWN_OPTION,
    ADDED_ALREADY,
    RECURSIVE_API_CALL,
    WAKEUP_FAILURE,
    BAD_FUNCTION_ARGUMENT,
    ABORTED_BY_CALLBACK,
    UNRECOVERABLE_POLL,
    LAST
};

} // namespace CurlWrapper
