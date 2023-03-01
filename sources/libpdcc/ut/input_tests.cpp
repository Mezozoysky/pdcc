#include <catch2/catch_test_macros.hpp>
#include <pd/cc/string_input.hpp>
#include <pd/cc/slurp_input.hpp>

using pd::cc::Input, pd::cc::StringInput, pd::cc::SlurpInput;

TEST_CASE("StringInput basic tests", "[Input][StringInput]")
{
    StringInput input;

    REQUIRE(input.isEnded());
    REQUIRE(input.currChar() == Input::END);
    REQUIRE(input.currLine() == 0u);
    REQUIRE(input.currCol() == 0u);

    std::string inputStr{"abc"};

    input.setStringCp(inputStr);

    REQUIRE(!input.isEnded());
    REQUIRE(input.currChar() == 'a');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 0u);

    input.setString(std::move(inputStr));

    REQUIRE(!input.isEnded());
    REQUIRE(input.currChar() == 'a');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 0u);

    char ch = input.nextChar();

    REQUIRE(!input.isEnded());
    REQUIRE(ch == 'b');
    REQUIRE(input.currChar() == ch);
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.lookupChar(1);

    REQUIRE(!input.isEnded());
    REQUIRE(ch == 'c');
    REQUIRE(input.currChar() == 'b');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.lookupChar(2);

    REQUIRE(!input.isEnded());
    REQUIRE(ch == Input::END);
    REQUIRE(input.currChar() == 'b');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.nextChar();

    REQUIRE(!input.isEnded());
    REQUIRE(input.currChar() == 'c');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 2u);

    ch = input.nextChar();

    REQUIRE(input.isEnded());
    REQUIRE(input.currChar() == Input::END);
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 3u);
}

TEST_CASE("SlurpInput basic tests", "[Input][SlurpInput]")
{
    SlurpInput input;

    REQUIRE(input.isEnded());
    REQUIRE(input.currChar() == Input::END);
    REQUIRE(input.currLine() == 0u);
    REQUIRE(input.currCol() == 0u);


    input.slurp("abc.txt");

    REQUIRE(!input.isEnded());
    REQUIRE(input.currChar() == 'a');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 0u);

    char ch = input.nextChar();

    REQUIRE(!input.isEnded());
    REQUIRE(ch == 'b');
    REQUIRE(input.currChar() == ch);
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.lookupChar(1);

    REQUIRE(!input.isEnded());
    REQUIRE(ch == 'c');
    REQUIRE(input.currChar() == 'b');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.lookupChar(2);

    REQUIRE(!input.isEnded());
    REQUIRE(ch == Input::END);
    REQUIRE(input.currChar() == 'b');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 1u);

    ch = input.nextChar();

    REQUIRE(!input.isEnded());
    REQUIRE(input.currChar() == 'c');
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 2u);

    ch = input.nextChar();

    REQUIRE(input.isEnded());
    REQUIRE(input.currChar() == Input::END);
    REQUIRE(input.currLine() == 1u);
    REQUIRE(input.currCol() == 3u);
}
