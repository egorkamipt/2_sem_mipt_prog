#ifndef ISPRIME_H
#define ISPRIME_H
#include <iostream>

template <size_t Key, size_t L, size_t R, size_t Mid = (R + L + 1) / 2>
struct Sqrt : Sqrt<Key, (((R >= 4000000000) || (Mid * Mid > Key)) ? L : Mid),
                   (((R >= 4000000000) || (Mid * Mid > Key)) ? Mid - 1 : R)> {};

template <size_t Key, size_t R>
struct Sqrt<Key, R, R, R> : std::integral_constant<size_t, R> {};

template <size_t Key>
inline const size_t kSqrtV = Sqrt<Key, 0, Key>::value;

template <size_t Key, size_t L, size_t R, size_t Mid = (R - L) / 2 + L>
struct Divisor : std::bool_constant<Divisor<Key, Mid + 1, R>::value || Divisor<Key, L, Mid>::value> {};

template <size_t Key, size_t Res>
struct Divisor<Key, Res, Res> : std::bool_constant<(Key % Res) == 0> {};

template <size_t Key, size_t L, size_t R>
inline const bool kHasDivisorOnV = Divisor<Key, L, R>::value;

template <size_t Key>
inline const bool kIsPrimeV = !kHasDivisorOnV<Key, 2, kSqrtV<Key>>;

template <>
inline const bool kIsPrimeV<1> = false;

template <>
inline const bool kIsPrimeV<2> = true;

template <>
inline const bool kIsPrimeV<3> = true;

#endif
