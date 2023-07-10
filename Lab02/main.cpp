#include <bits/stdc++.h>
#include <cassert>
using namespace std;

int gcd(long long int m, long long int n) {
  while (n > 0) {
    int r = m % n;
    m = n;
    n = r;
  }
  return m;
}

long long get_random_num(int n) {
  long int random_number = 2 + (rand() % (n - 3));
  return random_number;
}
unsigned long long int power(int a, int x, int n) {
  unsigned long long exp = 1;
  for (int i = 1; i <= x; i++) {
    exp = (exp * a) % n;
  }
  return exp;
}
bool is_prime(unsigned long long n) {
  int i = 1;
  int k = 2;
  if (n <= 1 || n == 4) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  while (i <= k) {
    long long int a = 2 + (rand() % (n - 3));
    if (gcd(a, n) != 1) {
      return false;
    }
    unsigned long long powered = power(a, n - 1, n);
    if (powered != 1) {
      return false;
    }
    i++;
  }
  return true;
}

int main() {
  srand(time(0));
  unsigned long long int x = 1000000007;
  ;
  cout << is_prime(x) << endl;
  return 0;
}
