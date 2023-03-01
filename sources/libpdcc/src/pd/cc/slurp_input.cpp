#include <pd/cc/slurp_input.hpp>
#include <cstdio>
#include <stdexcept>
#include <fmt/format.h>
#include <sstream>
#include <fstream>


using fmt::format;

namespace pd::cc
{

    SlurpInput::SlurpInput() noexcept
    : StringInputBase()
    {
    }

    void SlurpInput::slurp(std::string_view filename)
    {
        // std::FILE * fp = std::fopen(filename.data(), "r");
        // if (!fp)
        // {
        //     throw std::runtime_error(format("Failed to open file '{}'", filename.data()));
        // }

        // int ch;
        // std::ostringstream oss;
        // while (ch = std::fgetc(fp) != EOF)
        // {
        //     oss << (char)ch;
        // }
        // mString = oss.str();
        // fmt::print("string from file: {}", mString);

        std::ifstream ifs(filename.data());
        mString.assign((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

        resetCursor();
    }

} // namespace pd::cc
