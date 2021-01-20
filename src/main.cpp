// Copyright 2020 Polina Lukicheva
#include <iostream>

#include "postfix.h"

int main() {
  std::cout << infix2postfix("2 + 6 * 3 / (4 - 2)") << std::endl;
  std::cout << infix2postfix("2 + 2") << std::endl;
  std::cout << infix2postfix("(2 + 8.3) * (6 - 3.2)") << std::endl;
  std::cout << infix2postfix("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9")
            << std::endl;

  std::string inf = "2 + 2";
  std::string postf = infix2postfix(inf);
  std::cout << postf;
}
