class Solution {
public:
  string nextCountAndSay(string s) {
    ostringstream oss;
    
    char x = s[0];
    int count = 1;
    
    for(int index = 1; index < s.length(); ++index) {
      if(s[index] == x)
        ++count;
      else {
        oss << count << x;
        x = s[index];
        count = 1;
      }
    }
    oss << count << x;
    
    return oss.str();
  }
  
  string countAndSay(int n) {
    string s = "1";
    
    for(int i = 0; i < n-1; ++i)
      s = nextCountAndSay(s);
    
    return s;
  }
};
