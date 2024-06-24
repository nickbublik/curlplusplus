#pragma once

#include <memory>
#include <string>
#include <type_traits>

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

    EasyHandleBuilder& addOptionVoidPtr(const EasyOption opt, void* param);
    EasyHandleBuilder& addOptionString(const EasyOption opt, const std::string& param);
    EasyHandleBuilder& addOptionSList(const EasyOption opt, SList* param);

    template<typename Parameter>
    EasyHandleBuilder& addOption(const EasyOption opt, const Parameter& param)
    {   
        if (std::is_same_v<Parameter, std::string>)
        {
            return addOptionString(opt, param);
        }
        else if (std::is_same_v<Parameter, void*>)
        {
            return addOptionString(opt, param);
        }
        else if (std::is_same_v<Parameter, SList*>)
        {
            return addOptionSList(opt, param);
        }

        return *this;
    }

private:
    std::unique_ptr<Impl> m_impl;
};

} // namespace CurlWrapper
