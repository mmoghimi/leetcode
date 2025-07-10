class Solution {
public:
int H[256] = {0};
int S[256] = {0};
bool match(int H[], int S[]) {
  for(int c = 'A'; c <= 'z'; ++c)
    if(H[c] > S[c])
      return false;
  return true;
}
  
string minWindow(string s, string t) {
  for(int i = 0; i < t.length(); ++i)
    H[t[i]] += 1;
  
  int index1 = 0, index2 = 0;
  S[s[0]] = 1;
  
  int min_window_len = 1000000;
  string sub;
  
  while(index1<=index2 && index2<s.length()) {
    while(!match(H, S)) {
      ++index2;
      if (index2 == s.length()) {
        break;
      }
      S[s[index2]] += 1;
    }

    while(match(H, S)) {
      if(match(H, S) && index2-index1+1<min_window_len) {
        min_window_len = index2-index1+1;
        sub = s.substr(index1, min_window_len);
      }

      S[s[index1]] -= 1;
      ++index1;
    }
    }
  
  return sub;
}
};
