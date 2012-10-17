#ifndef SIEVE_HH
#define SIEVE_HH

#include <vector>
#include <utility>

namespace prime_sieve {
  template <typename T>
  std::vector<T> primes_in_range(const std::pair<T, T>&);
}

#include "sieve.inl"

#endif // #ifndef SIEVE_HH
