class Solution {
public:
  vector<vector<string>> res;
  
  void solveNQueens(int n, const vector<string>& partial, int queens_so_far, const vector<bool>& row_filled, const vector<bool>& diag1_filled, const vector<bool>& diag2_filled) {
    if(queens_so_far == n) {
      res.push_back(partial);
      return;
    }
    
    int c = queens_so_far;
    for(int r = 0; r < n; ++r)
      if(!row_filled[r] &&!diag1_filled[r+c] &&!diag2_filled[r-c+n]) {
          vector<string> new_partial = partial;
          new_partial[r][c] = 'Q';
        
          vector<bool> new_diag1_filled = diag1_filled;
          new_diag1_filled[r+c] = true;
        
          vector<bool> new_diag2_filled = diag2_filled;
          new_diag2_filled[r-c+n] = true;
        
          vector<bool> new_row_filled = row_filled;
          new_row_filled[r] = true;
        
          solveNQueens(n, new_partial, queens_so_far+1, new_row_filled, new_diag1_filled, new_diag2_filled);
        }
  }
  
  vector<vector<string>> solveNQueens(int n) {
    string n_dot;
    for(int i = 0; i < n; ++i)
      n_dot += '.';
    solveNQueens(n, vector<string>(n, n_dot), 0, vector<bool>(n, false), vector<bool>(2*n, false), vector<bool>(2*n, false));
    return res;
  }
};
