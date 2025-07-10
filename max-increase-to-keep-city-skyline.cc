class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<int> top(m, 0);
    vector<int> left(n, 0);
    
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j) {
        top[j] = max(top[j], grid[i][j]);
        left[i] = max(left[i], grid[i][j]);
      }

    int solution = 0;
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        solution += min(top[j], left[i]) - grid[i][j];
    
    return solution;
  }
};
