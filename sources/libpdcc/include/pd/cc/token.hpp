#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <variant>


namespace pd::cc
{

struct Token
{
    enum class Type
    {
        ERROR,

        INT_LITERAL,

        IDENTIFIER,

        RETURN,
        INT,

        L_BRACE,
        R_BRACE,
        L_PAREN,
        R_PAREN,
        SEMICOLON,

        END_OF_INPUT
    };

    using ValueType = std::variant<int, std::string>;

    Type type;
    ValueType value;

    Token(Type aType, ValueType && aValue = 0);
    ~Token() = default;
};

} // namespace pd::cc
