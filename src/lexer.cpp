#include <iostream>
#include <algorithm>

#include "lexer.hpp"

std::unordered_map<char, Lexer::Token> Lexer::token_map 
{
    {'+', plus},
    {'-', minus},
    {'*', multiply},
    {'/', divide},
    {'(', l_paren},
    {')', r_paren},
    {'n', number}
};

Lexer::Lexer(std::string exp){
    std::string::iterator end_pos = std::remove(exp.begin(), exp.end(), ' ');
    exp.erase(end_pos, exp.end());

    for (auto i = 0; i < exp.size(); i++)
    {
        char c = exp[i];
        if (isdigit(c))
        {
            auto last_digit = exp.find_first_not_of("012345869", i);
            auto number = exp.substr(i, last_digit - i);
            pairs.push_back(Pair(Token::number, stoi(number)));
            i = last_digit - 1;
        }
        else 
        {
            auto token = token_map[c];
            pairs.push_back(Pair(token, -1));
        }
    }

    for (auto pair : pairs)
    {
        std::cout << get_key(pair.token) << " ";
    }
}

Lexer::Pair Lexer::pop()
{
    auto pair = pairs.front();
    pairs.pop_front();
    return pair;
}

char Lexer::get_key(Token token)
{
    for (auto it = token_map.begin(); it != token_map.end(); ++it)
        if (it->second == token)
            return it->first;
}