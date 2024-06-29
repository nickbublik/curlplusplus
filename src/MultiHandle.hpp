#pragma once

#include <memory>
#include <chrono>

#include "Message.hpp"
#include "MultiCodes.hpp"
#include "EasyHandle.hpp"

namespace CurlWrapper
{

struct Impl;

class MultiHandle
{
public:
    MultiHandle();
    ~MultiHandle();

    void* getHandle() noexcept;

    MultiCode addEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept;
    MultiCode removeEasyHandle(std::shared_ptr<EasyHandle> easy_handle) noexcept;

    ///
    /// @brief wrapper on curl_multi_perform
    /// @returns pair where
    ///   pair.first is code on this operation 
    ///   pair.second is a number of running easy handlers
    ///
    std::pair<MultiCode, unsigned> perform() noexcept;

    ///
    /// @brief wrapper on curl_multi_poll
    /// @returns pair where
    ///   MultiCode is code on this operation 
    ///
    MultiCode poll(const std::chrono::milliseconds& timeout) noexcept;

    std::pair<Message, unsigned> info_read() noexcept;

private:
    std::unique_ptr<Impl> m_impl;
};

} // namespace CurlWrapper
