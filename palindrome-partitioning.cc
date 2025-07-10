class Solution {
public:
  bool ispalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
  }
  unordered_map<string, vector<vector<string>>> mem;
  
  vector<vector<string>> partition(string s) {
    if(mem.find(s) != mem.end())
      return mem[s];
    vector<vector<string>> res;
    if(!s.length())
      return res;
    
    for(int len = 1; len <= s.length(); ++len) {
      if(ispalindrome(s.substr(s.length()-len, len))) {
        vector<vector<string>> p = partition(s.substr(0, s.length()-len));
        if(!p.size())
          p.push_back(vector<string>());
        
        for(int i = 0; i < p.size(); ++i) {
          res.push_back(p[i]);
          res.back().push_back(s.substr(s.length()-len, len));
        }
      }
    }
    
    return mem[s] = res;
  }
};
