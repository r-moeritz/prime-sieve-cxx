#include "prime_sieve/sieve.hh"
#include <iostream>

using namespace std;
using namespace prime_sieve;

int main() {
  auto primes = primes_in_range( make_pair(100, 200) );

  for (auto& p : primes) {
    cout << p << " ";
  }
  cout << endl;
}
