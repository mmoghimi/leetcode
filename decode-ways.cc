class Solution {
public:
  int numDecodings(string s) {
    vector<int> DP(s.length()+1, 0);
    DP[0] = 1;
    for(int i = 1; i <= s.length(); ++i) {
      for(int j = 1; j <= 26; ++j) {
        if(j < 10 && s[i-1]=='0'+j%10)
          DP[i] += DP[i-1];
        if(j>=10 && i>=2 && s[i-2]=='0'+j/10 && s[i-1]=='0'+j%10)
          DP[i] += DP[i-2];
      }
    }
    return DP[s.length()];
  }
};
