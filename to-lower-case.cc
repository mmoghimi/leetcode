class Solution {
public:
string toLowerCase(string str) {
  string res;
  for(int i = 0; i < str.length(); ++i) {
    if(str[i] >= 'A' && str[i] <= 'Z') {
      res += (str[i]-'A'+'a');
    } else
      res += str[i];
  }
  return res;
}
};
