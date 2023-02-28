#pragma once

#include "input.hpp"
#include <string>
#include <cstddef>


namespace pd::cc
{

class StringInputBase
: public Input
{
public:
    virtual ~StringInputBase() noexcept = default;

    inline virtual bool isEnded() const override final { return (mCursor == mString.length()); }
    virtual char currChar() const override final;
    virtual char nextChar() override final;
    virtual char lookupChar(std::size_t offset = 1u) override final;

    inline virtual std::size_t currLine() const override final { return mLine; }
    inline virtual std::size_t currCol() const override final { return mCol; }

protected:
    StringInputBase() noexcept;
    virtual void resetCursor();

protected:
    std::string mString;
    std::size_t mCursor;
    std::size_t mLine;
    std::size_t mCol;
};

} // namespace pd::cc
