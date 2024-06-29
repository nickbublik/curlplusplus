#pragma once

#include <memory>
#include <string>
#include <type_traits>
#include <iostream>

#include "EasyOptions.hpp"
#include "SList.hpp"

namespace CurlWrapper
{

class EasyHandle;
struct Impl;

class EasyHandleBuilder
{
public:
    EasyHandleBuilder();
    ~EasyHandleBuilder();

    std::unique_ptr<EasyHandle> build() noexcept;

    using WriteCallbackFPtr = size_t (*)(char*, size_t, size_t, void*);

    template<typename Parameter>
    constexpr EasyHandleBuilder& addOption(const EasyOption opt, const Parameter& param)
    {   
        if constexpr (std::is_function_v<Parameter>)
        {
            return addOptionWriteCallback(opt, param);
        }
        else if constexpr (std::is_same_v<Parameter, std::string>)
        {
            return addOptionString(opt, param);
        }
        else if constexpr (std::is_same_v<Parameter, void*>)
        {
            return addOptionVoidPtr(opt, param);
        }
        else if constexpr (std::is_same_v<Parameter, SList*>)
        {
            return addOptionSList(opt, param);
        }

        return *this;
    }

private:
    EasyHandleBuilder& addOptionVoidPtr(const EasyOption opt, void* param);
    EasyHandleBuilder& addOptionString(const EasyOption opt, const std::string& param);
    EasyHandleBuilder& addOptionSList(const EasyOption opt, SList* param);
    EasyHandleBuilder& addOptionWriteCallback(const EasyOption opt, WriteCallbackFPtr param);

private:
    std::unique_ptr<Impl> m_impl;
};

} // namespace CurlWrapper
