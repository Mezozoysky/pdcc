#include <pd/cc/string_input_base.hpp>
#include <cassert>


namespace pd::cc
{

StringInputBase::StringInputBase() noexcept
: Input()
, mString{}
, mCursor{0u}
, mLine{0u}
, mCol{0u}
{
}

char StringInputBase::currChar() const
{
    if (isEnded())
    {
        return END;
    }
    return mString.data()[mCursor];
}

char StringInputBase::nextChar()
{
    assert(!isEnded());
    if (isEnded())
    {
        return END;
    }

    char ch = mString.data()[mCursor];
    if (ch == '\n')
    {
        ++mLine;
        mCol = 0u;
    }
    else if (ch == '\r')
    {
        // jist skip
    }
    else
    {
        ++mCol;
    }
    ++mCursor;

    return currChar();
}

char StringInputBase::lookupChar(std::size_t offset)
{
    if (mCursor + offset >= mString.length())
    {
        return END;
    }

    return mString.data()[mCursor + offset];
}

void StringInputBase::resetCursor()
{
    mCursor = 0u;
    mLine = 1u;
    mCol = 0u;
}

} // namespace pd::cc
