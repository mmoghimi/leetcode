class Solution {
public:
int countSubstrings(string s) {
  int count = 0;
  for (int i = 0; i < s.length(); ++i) {
    for(int j = 0; i+j < s.length() && i-j >= 0 && s[i-j]==s[i+j]; ++j)
      ++count;
    for(int j = 0; i+j+1 < s.length() && i-j >= 0 && s[i-j]==s[i+j+1]; ++j)
      ++count;
  }
  return count;
}
};
