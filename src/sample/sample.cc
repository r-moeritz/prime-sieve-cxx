#include "prime_sieve/sieve.hh"
#include <iostream>
#include <ctime>

using namespace std;
using namespace prime_sieve;

int main() {
  for (;;) {
    auto c1 = clock();
    auto primes = primes_in_range( make_pair(1, 10000000) );
    auto c2 = clock();
    getchar();
    cout << "Generated " << primes.size() << " primes in "
         << (c2 - c1)/static_cast<double>(CLOCKS_PER_SEC) << " seconds" << endl;
  }
}
