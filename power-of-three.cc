class Solution {
public:
    bool isPowerOfThree(int n) {
      if(!n) return false;
      double l = log(n)/log(3);
      return abs(l - round(l)) < 1e-10;
    }
};
