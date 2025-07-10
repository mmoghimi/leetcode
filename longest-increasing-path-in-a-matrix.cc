class Solution {
public:
  vector<vector<int>> mem;
  int longestIncreasingPath(vector<vector<int>>& matrix, int row, int col) {
    if(mem[row][col])
      return mem[row][col];
    int dir_row[4] = {0, 0, 1, -1};
    int dir_col[4] = {1, -1, 0, 0};
    
    int max_len = 1;
    for(int i = 0; i < 4; ++i) {
      int new_row = row + dir_row[i];
      int new_col = col + dir_col[i];
      if(new_row >= 0 && new_row < matrix.size() && new_col >= 0 && new_col < matrix[0].size()) {
        if(matrix[row][col] < matrix[new_row][new_col])
          max_len = max(max_len, 1+longestIncreasingPath(matrix, new_row, new_col));
      }
    }
    
    return mem[row][col]=max_len;
  }
  
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(!matrix.size())
      return 0;
    mem = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
    int max_len = 0;
    for(int i = 0; i < matrix.size(); ++i)
      for(int j = 0; j < matrix[0].size(); ++j) {
        // cout << i << " " << j << " " << longestIncreasingPath(matrix, i, j) << endl;
        max_len = max(max_len, longestIncreasingPath(matrix, i, j));
      }
    return max_len;
  }
};
