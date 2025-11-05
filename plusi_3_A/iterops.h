#ifndef ITEROPS_H
#define ITEROPS_H
#include <iostream>

template <class IteratorType>
void Advance(IteratorType& iterator, int dist) {
  using Category = typename std::iterator_traits<IteratorType>::iterator_category;
  if constexpr (std::is_same_v<Category, std::random_access_iterator_tag>) {
    iterator += dist;
    return;
  } else {
    while (dist > 0) {
      --dist;
      ++iterator;
    }
    if constexpr (std::is_same_v<Category, std::bidirectional_iterator_tag>) {
      while (dist < 0) {
        ++dist;
        --iterator;
      }
    }
  }
}

template <class IteratorType>
IteratorType Next(IteratorType iterator, int dist = 1) {
  Advance(iterator, dist);
  return iterator;
}

template <class IteratorType>
IteratorType Prev(IteratorType iterator, int dist = 1) {
  Advance(iterator, -dist);
  return iterator;
}

template <class IteratorType>
int Distance(IteratorType first, IteratorType second) {
  using Category = typename std::iterator_traits<IteratorType>::iterator_category;
  if constexpr (std::is_same_v<Category, std::random_access_iterator_tag>) {
    return second - first;
  }
  int dist = 0;
  while (first != second) {
    ++first;
    ++dist;
  }
  return dist;
}

#endif
