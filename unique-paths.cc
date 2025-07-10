class Solution {
public:
int uniquePaths(int m, int n) {
  if(m == 0 || n == 0)
    return 0;
  
  vector<vector<int>> num_paths(m, vector<int>(n, 0));
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j)
      if(i == 0 && j == 0)
        num_paths[i][j] = 1;
      else if (i == 0)
        num_paths[i][j] = num_paths[i][j-1];
      else if (j == 0)
        num_paths[i][j] = num_paths[i-1][j];
      else        
        num_paths[i][j] = num_paths[i-1][j] + num_paths[i][j-1];
  
  return num_paths[m-1][n-1];
}
};
