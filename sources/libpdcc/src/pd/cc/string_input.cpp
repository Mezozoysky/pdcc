#include <pd/cc/string_input.hpp>


namespace pd::cc
{

StringInput::StringInput() noexcept
: StringInputBase()
{
}

StringInput::StringInput(std::string && str)
: StringInputBase()
{
    setString(std::move(str));
}

void StringInput::setString(std::string && str)
{
    mString = std::move(str);
    resetCursor();
}

void StringInput::setStringCp(std::string const & str)
{
    mString = str;
    resetCursor();
}

} // namespace pd::cc
