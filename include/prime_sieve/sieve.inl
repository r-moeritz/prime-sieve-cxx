// -*- mode: C++ -*-

#include <map>
#include <cmath>

using namespace std;

template <typename T1, typename T2>
static void fill_map_with_range(map<T1, T2>& m, const pair<T1, T1>& range, const T2& value) {
  for (auto i = range.first; i != range.second; ++i) {
    m.insert({ i, value });
  }
}

template<typename T>
vector<T> prime_sieve::primes_in_range(const pair<T, T>& range) {
  map<T, bool> m;
  fill_map_with_range(m, range, false);

  // main part of the sieve of atkin
  auto root = ceil(sqrt(range.second));
  for (auto x = 1; x <= root; ++x) {
    for (auto y = 1; y <= root; ++y) {
      auto x2 = x*x;
      auto y2 = y*y;

      auto n = (4*x2) + y2;
      if (n >= range.first && n < range.second && (n%12 == 1 || n%12 == 5)) {
        m[n] ^= true;
      }

      n = (3*x2) + y2;
      if (n >= range.first && n < range.second && n%12 == 7) {
        m[n] ^= true;
      }

      n = (3*x2) - y2;
      if (x > y && n >= range.first && n < range.second && n%12 == 11) {
        m[n] ^= true;
      }
    }
  }

  // mark 2 & 3 as prime, if in range
  if (m.find(2) != m.end()) {
    m[2] = true;
  }
  if (m.find(3) != m.end()) {
    m[3] = true;
  }

  // mark all multiples of primes as non-prime
  for (auto r = 5; r <= root; ++r) {
    if (m[r]) {
      auto r2 = r*r;
      for (auto i = r2; i < range.second; i += r2) {
        m[i] = false;
      }
    }
  }

  vector<T> primes;
  for (auto& p : m) {
    if (p.second) {
      primes.push_back(p.first);
    }
  }

  return primes;
}
