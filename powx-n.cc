class Solution {
public:
  double myPow(double x, int n) {
    double f = 1;
    if(n == INT_MIN) {
      n = INT_MAX;
      x = 1/x;
      f = x;
    }
    if(n<0) {
      x = 1/x;
      n = -n;
    }
    if(n == 1)
      return x;
    
    if(n == 0)
      return 1;
    
    double p = myPow(x, n/2);
    return p*p*(n%2?x:1)*f;
  }
};
