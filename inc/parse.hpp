#ifndef PARSE_HPP
#define PARSE_HPP

#include <cmath>
#include <string>
#include <string_view>
#include <vector>

double parser(std::string input);
bool check_valid_brackets(std::string_view calc);
void remove_chars_if_not(std::string &s, std::string_view allowed);
std::vector<std::string> split_input(std::string calculation);
size_t find_closing_paren(const std::string &s, size_t pos);
#endif //MAIN_HPP
