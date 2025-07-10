class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    vector<bool> is_prime(32, false);
    for(int p: primes)
      is_prime[p] = true;
    
    int res = 0;
    for(int i = L; i <= R; ++i) {
      int x = i;
      int c = 0;
      while(x) {
        c += x%2;
        x /= 2;
      }
      res += is_prime[c];
    }
    return res;
  }
};
