class Solution {
public:
string s, p;
int mem[100][100];
bool isMatch(int m, int n) {
  if(mem[m][n] >= 0)
    return mem[m][n];
  
  if(s.substr(0, m) == p.substr(0, n)) return mem[m][n] = true;
  if(n == 0 && m > 0)
    return mem[m][n] = false;
  if(m == 0 && n > 0) {
    if(p[n-1] == '*')
      return mem[m][n] = isMatch(m, n-2);
    else
      return mem[m][n] = false;  
  } 
  
  if(s[m-1] == p[n-1])
    return mem[m][n] = isMatch(m-1, n-1);
  else if (p[n-1] == '.')
    return mem[m][n] = isMatch(m-1, n-1);
  else if (p[n-1] == '*') {
    return mem[m][n] = (p[n-2] == '.' && isMatch(m-1, n))
        || (p[n-2] == s[m-1] && isMatch(m-1, n))
        || isMatch(m, n-2);
  } else
    return mem[m][n] = false;
}
  
bool isMatch(string s, string p) {
  this->s = s;
  this->p = p;
  for(int i = 0; i < 100; ++i)
  for(int j = 0; j < 100; ++j)
    mem[i][j] = -1;
  return isMatch(s.length(), p.length());
}
};
