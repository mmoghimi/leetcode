class Solution {
public:
  int firstUniqChar(string s) {
    int hist[256] = {0};
    for(int i = 0; i < s.length(); ++i)
      hist[s[i]] += 1;
    for(int i = 0; i < s.length(); ++i)
      if(hist[s[i]] == 1)
        return i;
    return -1;
  }
};
