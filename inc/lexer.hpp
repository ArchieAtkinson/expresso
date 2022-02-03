#pragma once
#include <string>
#include <unordered_map>
#include <deque>


class Lexer{
  private:

    enum Token{
        plus,
        minus,
        multiply,
        divide,
        
        number,

        l_paren,
        r_paren,
    };
    public:

    struct Pair{
        Pair(Token token, int value) : token{token}, value{value} {};
        Token token;
        int value;
    };
    
    Lexer(std::string expression);
    Pair pop();
    char get_key(Token token);

    private:
      static std::unordered_map<char, Token> token_map;
      std::deque<Pair> pairs;

      
};