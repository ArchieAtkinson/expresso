#include <iostream>


#include "parse.hpp"



int main() {
  std::string input;
#ifdef DEBUG
    std::cout << parser("10.1 + 10 + 20 - 10");
#else 
   while(std::getline(std::cin, input)) { // quit the program with ctrl-d
      std::cout << parser(input);
  }   
#endif
}