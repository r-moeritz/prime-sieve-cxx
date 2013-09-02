#include "prime_sieve/sieve.hh"
#include <iostream>
#include <array>
#include <ctime>

using namespace std;
using namespace prime_sieve;

int main() {
  array<int, 4> nv = { 1000000, 10000000, 100000000, 1000000000 };

  for (auto& n : nv) {
    auto c1 = clock();
    auto primes = primes_lt_n(n);
    auto c2 = clock();
    cout << "Found " << primes.size() << " primes in "
         << (c2 - c1)/static_cast<double>(CLOCKS_PER_SEC) << " seconds" << endl;
  }
}

/*
Found 78499 primes in 0.019 seconds
Found 664580 primes in 0.129 seconds
Found 5761456 primes in 2.119 seconds
Found 53327625 primes in 33.126 seconds
*/
