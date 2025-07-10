class Solution {
public:
void swap(char& x, char& y) {
  char temp = x;
  x = y;
  y = temp;
}
void reverseString(vector<char>& s) {
  int n = s.size();
  for(int i = 0; i < s.size()/2; ++i) 
    swap(s[i], s[n-1-i]);
}
};
