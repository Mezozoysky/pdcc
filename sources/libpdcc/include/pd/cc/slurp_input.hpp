#pragma once

#include "string_input_base.hpp"
#include <string_view>


namespace pd::cc
{

    class SlurpInput
        : public StringInputBase
    {
    public:
        SlurpInput() noexcept;
        virtual ~SlurpInput() noexcept = default;

        void slurp(std::string_view filename);
    };

} // namespace pd::cc
