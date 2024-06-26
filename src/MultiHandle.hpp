#pragma once

#include <memory>

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

    std::pair<MultiCode, unsigned> perform() noexcept;

private:
    std::unique_ptr<Impl> m_impl;
};

} // namespace CurlWrapper
