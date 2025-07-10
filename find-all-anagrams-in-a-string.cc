class Solution {
public:
vector<int> findAnagrams(string s, string p) {
  vector<int> anagrams;
  if(s.length() < p.length())
    return anagrams;
  
  int hist[26] = {0};
  int phist[26] = {0};
  for(int i = 0; i < p.length(); ++i) {
    ++phist[p[i]-'a'];
    ++hist[s[i]-'a'];
  }
    
  for(int i = 0; i+p.length()-1<s.length(); ++i) {
    if(i>0) {
      --hist[s[i-1]-'a'];
      ++hist[s[i+p.length()-1]-'a'];
    }
    
    bool same = true;
    for(int j = 0; j < 26; ++j)
      if(phist[j] != hist[j]) {
        same = false;
        break;
      }
    if(same)
      anagrams.push_back(i);
  }
  return anagrams;
}
};
