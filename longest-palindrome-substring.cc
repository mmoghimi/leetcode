
class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.length();
      int max_len = 0;
      int start_index = 0;
      for(int center=0; center < s.length(); ++center) {
        int len = 0;
        while(center-len >= 0 && center+len<n && s[center+len]==s[center-len])
          ++len;
        if(2*len-1>max_len) {
          max_len = 2*len-1;
          start_index = center-len+1;
        }
      }      
      
      for(int center=0; center < s.length(); ++center) {
        int len = 0;
        while(center-len >= 0 && center+len+1<n && s[center+len+1]==s[center-len])
          ++len;
        if(2*len>max_len) {
          max_len = 2*len;
          start_index = center-len+1;
        }
      }
      return s.substr(start_index, max_len);
    }
};
