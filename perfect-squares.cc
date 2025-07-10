class Solution {
public:
  int mem[10000] = {0};
  int numSquares(int n) {
    if(mem[n])
      return mem[n];
    if(n == 0)
      return 0;
    
    int min_squares = INT_MAX;
    for(int i = 1; i*i <= n; ++i)
      min_squares = min(min_squares, numSquares(n-i*i)+1);
    return mem[n] = min_squares;
  }
};
