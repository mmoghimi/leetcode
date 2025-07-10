class Solution {
public:
  int ssq(int n) {
    int res = 0;
    while(n) {
      res += (n%10) * (n%10);
      n /= 10;
    }
    return res;
  }
  
  bool isHappy(int n) {
    unordered_set<int> s;
    while(s.find(n) == s.end()) {
      s.insert(n);
      n = ssq(n);
    }
    return n == 1;
  }
};
