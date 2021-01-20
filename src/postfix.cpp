// Copyright 2020 Polina Lukicheva
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  std::string postfix;
  Stack<char> stack(200);
  int i = 0;
  while (i < infix.size()) {
    if (infix[i] == '(') {
      stack.push(infix[i++]);
    } else {
      if (infix[i] == ')') {
        while (!stack.isEmpty() && stack.get() != '(') {
          postfix += stack.pop();
          postfix += ' ';
        }
        if (stack.get() == '(') stack.pop();
        ++i;
      } else {
        if (infix[i] == '*' ||
            infix[i] == '/') {
          if (stack.get() == '/' ||
            stack.get() == '*' ||
            stack.get() == ')') {
            while (!stack.isEmpty() &&
              stack.get() != '(' &&
              stack.get() != '+' &&
              stack.get() != '-') {
              postfix += stack.pop();
              postfix += ' ';
            }
            if (stack.get() == '(') stack.pop();
            stack.push(infix[i++]);
          } else {
            stack.push(infix[i++]);
          }
        } else {
          if (infix[i] == '+' ||
            infix[i] == '-') {
            while (!stack.isEmpty() &&
              stack.get() != '(') {
              postfix += stack.pop();
              postfix += ' ';
            }
            if (stack.get() == '(') stack.pop();
            stack.push(infix[i++]);
          } else {
            if (infix[i] != ' ') {
              while (infix[i] >= '0' &&
                infix[i] <= '9' ||
                infix[i] == '.') {
                postfix += infix[i++];
              }
              postfix += ' ';
            } else {
              i++;
            }
          }
        }
      }
    }
  }
  while (!stack.isEmpty()) {
    postfix += stack.pop();
    postfix += ' ';
  }
  postfix.erase(postfix.size() - 1);
  return postfix;
}
