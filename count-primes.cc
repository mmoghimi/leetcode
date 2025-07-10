class Solution {
public:
  inline bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n)+2 && i < n; ++i)
      if(n % i == 0)
        return false;
    return true;
  }
  
  int countPrimesWithFunction(int n) {
    int prime_count = 0;
    for(int i = 2; i < n; ++i)
      if(isPrime(i))
        ++ prime_count;
    return prime_count;
  }
  
  int countPrimes(int n) {
    vector<bool> is_prime(n+1, true);
    int prime_count = 0;
    for(int i = 2; i <= n/2; ++i) {
      for(int k = 2*i; k <= n; k += i)
        is_prime[k] = false;
    }
    
    for(int i = 3; i < n; i+=2)
      if(is_prime[i])
        ++prime_count;
    
    if(n>2)
      ++prime_count;
      
    return prime_count;
  }
};
