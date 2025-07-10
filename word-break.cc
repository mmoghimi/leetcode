class Solution {
public:
  
bool wordBreak(string s, vector<string>& wordDict) {
  vector<bool> mem = vector<bool>(10000, false);
  mem[0] = true;

  for(int n = 1; n <= s.length(); ++n) {
    for(auto w: wordDict) {
      if(n < w.length())
          continue;
        
      bool same = true;
      for(int j = 0; j < w.length(); ++j)
        if(s[n-w.length()+j] != w[j]) {
          same = false;
          break;
        }

      if(same && mem[n-w.length()]) {
         mem[n] = true;
         break;
      }
    }
  }
    
  return mem[s.length()];
}
  
};
