#pragma once

#include "string_input_base.hpp"


namespace pd::cc
{

class StringInput
: public StringInputBase
{
public:
    StringInput() noexcept;
    explicit StringInput(std::string && str);
    virtual ~StringInput() noexcept = default;

    void setString(std::string && str);
    void setStringCp(std::string const & str);
};

} // namespace pd::cc
