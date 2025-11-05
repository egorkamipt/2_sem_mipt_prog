#ifndef STACK_H
#define STACK_H

#include <deque>
#include <iostream>

template <class T, class Container = std::deque<T>>
struct Stack {
  Container x;
  Stack() = default;
  explicit Stack(const Container& container);
  template <class Iterator>
  Stack(Iterator begin, Iterator end);
  T& Top();
  const T& Top() const;
  size_t Size() const;
  void Push(const T& value);
  bool Empty() const;
  template <class... Args>
  void Emplace(Args&&... args);
  void Pop();
  void Swap(Stack& other);
  void Push(T&& value);
};

template <class T, class Container>
void Stack<T, Container>::Push(T&& value) {
  x.push_back(std::move(value));
}

template <class T, class Container>
void Stack<T, Container>::Swap(Stack& other) {
  std::swap(x, other.x);
}

template <class T, class Container>
void Stack<T, Container>::Pop() {
  x.pop_back();
}

template <class T, class Container>
template <class... Args>
void Stack<T, Container>::Emplace(Args&&... args) {
  x.emplace_back(std::forward<Args>(args)...);
}

template <class T, class Container>
bool Stack<T, Container>::Empty() const {
  return x.empty();
}

template <class T, class Container>
void Stack<T, Container>::Push(const T& value) {
  x.push_back(value);
}

template <class T, class Container>
size_t Stack<T, Container>::Size() const {
  return x.size();
}

template <class T, class Container>
const T& Stack<T, Container>::Top() const {
  return x.back();
}

template <class T, class Container>
T& Stack<T, Container>::Top() {
  return x.back();
}

template <class T, class Container>
template <class Iterator>
Stack<T, Container>::Stack(Iterator begin, Iterator end) : x(begin, end) {
}

template <class T, class Container>
Stack<T, Container>::Stack(const Container& container) {
  x = container;
}

#endif
