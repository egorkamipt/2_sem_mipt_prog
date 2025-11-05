#ifndef ARRAY_TRAITS_H
#define ARRAY_TRAITS_H
#include <iostream>

template <class T>
const bool kIsArrayV = false;

template <class T>
const bool kIsArrayV<T[]> = true;

template <class T, size_t N>
const bool kIsArrayV<T[N]> = true;

template <class T>
struct kRank : std::integral_constant<size_t, 0> {};  // NOLINT

template <class T>
inline constexpr size_t kRankV = kRank<T>::value;

template <class T>
struct kRank<T[]> : std::integral_constant<size_t, kRankV<T> + 1> {};

template <class T, size_t N>
struct kRank<T[N]> : std::integral_constant<size_t, kRankV<T> + 1> {};

template <class T>
const int kSizeV = 1;

template <class T>
const int kSizeV<T[]> = 0;

template <class T, size_t N>
const int kSizeV<T[N]> = N;

template <class T>
const int kTotalSizeV = 1;

template <class T>
const int kTotalSizeV<T[]> = 0;

template <class T, size_t N>
const int kTotalSizeV<T[N]> = kTotalSizeV<T> * N;

template <class T>
struct ArrayUnder {
  using Type = T;
};

template <class T>
struct ArrayUnder<T[]> {
  using Type = T;
};

template <class T, size_t N>
struct ArrayUnder<T[N]> {
  using Type = T;
};

template <class T>
using RemoveArrayT = typename ArrayUnder<T>::Type;

template <class T>
struct RemoveAllArrays {
  using Type = T;
};

template <class T>
using RemoveAllArraysT = typename RemoveAllArrays<T>::Type;

template <class T>
struct RemoveAllArrays<T[]> {
  using Type = RemoveAllArraysT<T>;
};

template <class T, size_t N>
struct RemoveAllArrays<T[N]> {
  using Type = RemoveAllArraysT<T>;
};

#endif
