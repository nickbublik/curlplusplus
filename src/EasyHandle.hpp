#pragma once

#include <memory>

namespace CurlWrapper
{

struct Impl;

class EasyHandle
{
public:
    EasyHandle();
    ~EasyHandle();

    void* getHandle() noexcept;

private:
    std::unique_ptr<Impl> m_impl;
};

} // namespace CurlWrapper
