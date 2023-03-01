#include <pd/cc/token.hpp>

namespace pd::cc
{

Token::Token(Type aType, ValueType && aValue)
: type{aType}
, value{std::move(aValue)}
{
}

} // namespace pd::cc
