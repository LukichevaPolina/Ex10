// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <class T>
class Stack {
 private:
  T* stack;
  size_t size;
  int top;

 public:
  explicit Stack(size_t);
  Stack(const Stack&);
  ~Stack() { delete[] stack; }
  T get() const;
  T pop();
  void push(T);
  bool isFull() const;
  bool isEmpty() const;
};
template <class T>
Stack<T>::Stack(size_t _size) {
  stack = new T[_size];
  size = _size;
  top = -1;
}
template <class T>
Stack<T>::Stack(const Stack& _myStack) {
  stack = new T[_myStack.size];
  size = _myStack.size;
  top = _myStack.top;
  for (int i = 0; i <= top; ++i) {
    stack[i] = _myStack.stack[i];
  }
}
template <class T>
T Stack<T>::get() const {
  if (!this->isEmpty()) return this->stack[top];
}
template <class T>
T Stack<T>::pop() {
  if (!this->isEmpty()) return this->stack[this->top--];
}
template <class T>
void Stack<T>::push(T elem) {
  if (!this->isFull()) this->stack[++this->top] = elem;
}
template <class T>
bool Stack<T>::isEmpty() const {
  return (top == -1);
}
template <class T>
bool Stack<T>::isFull() const {
  return (top == size - 1);
}
#endif  // INCLUDE_MYSTACK_H_
