#include "parse.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Validates correct brackets", "[check_valid_brackets]")
{
    REQUIRE(check_valid_brackets("") == true);
    REQUIRE(check_valid_brackets("()") == true);
    REQUIRE(check_valid_brackets("(foo)") == true);
    REQUIRE(check_valid_brackets("(foo(bar))") == true);
    REQUIRE(check_valid_brackets("(foo(bar)foo)") == true);

    REQUIRE(check_valid_brackets("(") == false);
    REQUIRE(check_valid_brackets(")") == false);
    REQUIRE(check_valid_brackets("())") == false);
    REQUIRE(check_valid_brackets("(foo)bar)") == false);
    REQUIRE(check_valid_brackets("(()") == false);
    REQUIRE(check_valid_brackets("(bar(foo)") == false);

    REQUIRE(check_valid_brackets("(^bar)") == false);
    REQUIRE(check_valid_brackets("(foo^)") == false);
}

TEST_CASE("Removes characters if not present", "[remove_chars_if_not]")
{
    std::string foo = "abc";
    remove_chars_if_not(foo, "ab");
    REQUIRE(foo == "ab");
}

TEST_CASE("Find closing parenthese given open parenthese postion", "[find_closing_paren]")
{
    REQUIRE(find_closing_paren("()", 0) == 1);
}

TEST_CASE("Spliting input into operations and values", "[split_input]")
{
    REQUIRE(split_input("((10+10)+20)") == std::vector<std::string>{"((10+10)+20)"});
    REQUIRE(split_input("(10+20)2^2") == std::vector<std::string>{"(10+20)", "2^2"});

    

    // out = split_input("(10+20)-5*2+2^2/10");
    // REQUIRE(out == std::vector<std::string>{"(10 + 20)", "-", "5", "*", "2", "+", "2^2", "/", "10"});

    // out = split_input("(10+20)-5a*2+2^2/10");
    // REQUIRE(out == std::vector<std::string>{});
}