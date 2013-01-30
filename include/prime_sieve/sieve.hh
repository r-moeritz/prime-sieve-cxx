#ifndef SIEVE_HH
#define SIEVE_HH

#include <vector>
#include <utility>

namespace prime_sieve {
  template <typename T>
  std::vector<T> primes_in_range(const std::pair<T, T>&);

  template <typename T>
  std::vector<T> primes_lt_n(const T n);
}

#include "sieve.inl-cc"

#endif // #ifndef SIEVE_HH
