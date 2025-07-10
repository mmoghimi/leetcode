class Solution {
public:
  vector<string> res;
  vector<string> wordDict;
  string s;
  bool isBreakable(string s, vector<string>& wordDict) {
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

  void wordBreak(int start, const string& so_far) {
    if(start == s.length()) {
      res.push_back(so_far);
      return;
    }
    
    for(auto& w: wordDict) {
      bool same = true;
      for(int i = 0; i < w.length(); ++i)
        if(start+i >= s.length() || w[i] != s[start+i]) {
          same = false;
          break;
        }
      if(same) {
        string new_so_far = so_far + (so_far.length()?" ":"") + w;
        wordBreak(start+w.length(), new_so_far);
      }
    }
  }
  
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    if(isBreakable(s, wordDict)) {
      this->wordDict = wordDict;
      this->s = s;
      wordBreak(0, "");
    }
    return res;
  }
  
};
