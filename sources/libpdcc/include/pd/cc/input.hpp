#pragma once

#include <cstddef>


namespace pd::cc
{

class Input
{
public:
    static const char END{0x04};

    Input() noexcept = default;
    virtual ~Input() noexcept = default;

    virtual bool isEnded() const = 0;
    virtual char currChar() const = 0;
    virtual char nextChar() = 0;
    virtual char lookupChar(std::size_t offset = 1u) = 0;

    virtual std::size_t currLine() const = 0;
    virtual std::size_t currCol() const = 0;
};

} // namespace pd::cc

