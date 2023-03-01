#include <catch2/catch_test_macros.hpp>
#include <pd/cc/token.hpp>

using pd::cc::Token;

TEST_CASE("Token basic tests", "[Token][Scanner]")
{
    Token token{Token::Type::ERROR, "error message"};
    REQUIRE(token.type == Token::Type::ERROR);
    REQUIRE(std::get<std::string>(token.value) == "error message");

    token = Token{Token::Type::INT_LITERAL, 8};
    REQUIRE(token.type == Token::Type::INT_LITERAL);
    REQUIRE(std::get<int>(token.value) == 8);

    token = Token{Token::Type::IDENTIFIER, "some_id"};
    REQUIRE(token.type == Token::Type::IDENTIFIER);
    REQUIRE(std::get<std::string>(token.value) == "some_id");

    token = Token{Token::Type::RETURN};
    REQUIRE(token.type == Token::Type::RETURN);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::INT};
    REQUIRE(token.type == Token::Type::INT);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::L_BRACE};
    REQUIRE(token.type == Token::Type::L_BRACE);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::R_BRACE};
    REQUIRE(token.type == Token::Type::R_BRACE);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::L_PAREN};
    REQUIRE(token.type == Token::Type::L_PAREN);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::R_PAREN};
    REQUIRE(token.type == Token::Type::R_PAREN);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::SEMICOLON};
    REQUIRE(token.type == Token::Type::SEMICOLON);
    REQUIRE(std::get<int>(token.value) == 0);

    token = Token{Token::Type::END_OF_INPUT};
    REQUIRE(token.type == Token::Type::END_OF_INPUT);
    REQUIRE(std::get<int>(token.value) == 0);
}
