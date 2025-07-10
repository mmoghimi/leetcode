class Solution {
public:
    int fib[10000] = {0};
    int climbStairs(int n) {
      if(fib[n])
        return fib[n];
      if(n <= 1)
        return 1;
      if(n == 2)
        return 2;
      
      return fib[n] = climbStairs(n-2) + climbStairs(n-1);
    }
};
