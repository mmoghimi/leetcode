class Solution {
public:
    bool isPalindrome(string s) {
      string cleaned_s;
      for(char c: s)
        if(isalnum(c))
          cleaned_s += tolower(c);
      string r = cleaned_s;
      reverse(r.begin(), r.end());
      return r == cleaned_s;
    }
};
