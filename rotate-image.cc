class Solution {
public:
  void swap(int& a, int& b, int& c, int &d) {
  int tmp = a;
  a = b;
  b = c;
  c = d;
  d = tmp;
}


void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for(int r = 0; 2*r<n; ++r)
    for(int i = 0; i < n-1-2*r; ++i)
      swap(matrix[r][i+r], matrix[n-1-r-i][r], matrix[n-1-r][n-r-1-i], matrix[i+r][n-1-r]);
}
};
