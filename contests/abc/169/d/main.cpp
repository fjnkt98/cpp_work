#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<uint64_t, uint64_t>> prime_factorize(uint64_t N) {
  vector<pair<uint64_t, uint64_t>> primes;
  for (uint64_t i = 2; i * i <= N; i++) {
    if (N % i != 0)
      continue;

    uint64_t ex = 0;
    while (N % i == 0) {
      ex++;
      N /= i;
    }
    primes.push_back({i, ex});
  }
if (N != 1)
  primes.push_back({N, 1});

  return primes;
}

int main() {
  uint64_t N;
  cin >> N;

  const auto &primes = prime_factorize(N);

  int counter = 0;

  for (auto p : primes) {
    int a = p.second;
    int i = 1;
    while (a - i >= 0) {
      a -= i;
      i++;
      counter++;
    }
  }

  cout << counter << endl;
}