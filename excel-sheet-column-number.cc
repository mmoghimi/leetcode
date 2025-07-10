class Solution {
public:
  int titleToNumber(string s) {
    long long x = 0;
    
    for(int i = 0; i < s.length(); ++i)
       x = x*26 + s[i]-'A'+1;
    
    return x;
  }
};
