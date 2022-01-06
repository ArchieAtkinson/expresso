#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stack>

#include "parse.hpp"

constexpr std::string_view  OPERATIONS = "()^/*-+";
constexpr std::string_view  NUMBERS = "0123456789";
constexpr std::string_view VALID_CHAR = "0123456789()^/*-+";

bool check_valid_brackets(std::string_view calc)
{
    std::stack<char> paren;
    for (size_t i = 0; i < calc.size(); i++)
    {
        switch (calc[i])
        {
        case '(':
            if(calc[i + 1] == '^')
                return false;
            paren.push(calc[i]);
            break;
        case ')':
            if (paren.empty() || paren.top() != '(' || calc[i-1] == '^')
                return false;
            else
            {
                paren.pop();
                break;
            }
        default:
            continue;
        }
    }
    return paren.empty();
}

size_t find_closing_paren(const std::string &s, size_t pos)
{
    size_t counter = 1;
    while (counter > 0) {
        char c = s[++pos];
        if (c == '(') 
            counter++;
        else if (c == ')')
            counter--;
    }
    return pos;
}

std::vector<std::string> split_input(std::string calc)
{
    assert(calc.find_first_of(VALID_CHAR) == std::string::npos);

    std::vector<std::string> split;
    for (size_t i = 0; i < calc.size(); i++)
    {

        if (calc[i] == '(')
        {
            auto pos = find_closing_paren(calc, i);
            std::string brackets = calc.substr(i, pos + 1 - i);
            split.push_back(brackets);
            i = pos;
        }
        else if (calc[i] == '^')
        {
            if (i == 0)
            {
                std::cout << "Bad Indices" << std::endl;
                return std::vector<std::string>{};
            }
            size_t caret_pos = i;
            size_t front_pos = calc.find_last_of(NUMBERS, caret_pos);
            if (front_pos == std::string::npos)
                front_pos = 0;
            else
                front_pos++;

            std::string caret_add = "^+";
            std::string caret_sub = "^-";

            size_t back_pos = calc.find_first_not_of(NUMBERS, caret_pos);
            if (back_pos == std::string::npos)
                back_pos = calc.size();

            std::string indices = calc.substr(front_pos, back_pos + 1 - front_pos);
            split.push_back(indices);
            i = back_pos;
        }
        else if (calc[i] == '/')
        {
        }
        else if (calc[i] == '*')
        {
        }
        else if (calc[i] == '+')
        {
        }
        else if (calc[i] == '-')
        {
        }
        else
        {
            // std::cout << "Invalid Brackets" << std::endl;
            // return std::vector<std::string>{};
        }
    }

    return split;
}

void remove_chars_if_not(std::string& s,std::string_view allowed)
{
    s.erase(std::remove_if(s.begin(), s.end(), [&allowed](const char &c) { return allowed.find(c) == std::string::npos; }),
            s.end());
}

double parser(std::string input)
{
    remove_chars_if_not(input, VALID_CHAR);
    if (input.empty())
        std::cout << "Empty Input" << std::endl;
    if (!check_valid_brackets(input))
        std::cout << "Invalid Brackets" << std::endl;
    
    return 0;
}
