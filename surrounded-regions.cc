class Solution {
public:
  void floodfill(vector<vector<char>>& board, int r, int c) {
    if(board[r][c] == 'N')
      return;
    
    board[r][c] = 'N';
    
    int dir_r[4] = {0, 0, 1, -1};
    int dir_c[4] = {1, -1, 0, 0};
    
    for(int k = 0; k < 4; ++k) {
      int new_r = r + dir_r[k];
      int new_c = c + dir_c[k];
      if(new_r >= 0 && new_r < board.size() && new_c >= 0 && new_c < board[0].size() && board[new_r][new_c] == 'O')
        floodfill(board, new_r, new_c);
    }
  }
  
  void solve(vector<vector<char>>& board) {
    if(!board.size())
      return;
    int num_rows = board.size();
    int num_cols = board[0].size();
    for(int i = 0; i < num_rows; ++i) {
      if(board[i][0] == 'O')
        floodfill(board, i, 0);
      if(board[i][num_cols-1] == 'O')
        floodfill(board, i, num_cols-1);
    }
    for(int i = 0; i < num_cols; ++i) {
      if(board[0][i] == 'O')
        floodfill(board, 0, i);
      if(board[num_rows-1][i] == 'O')
        floodfill(board, num_rows-1, i);
    }
    
    for(int r = 0; r < num_rows; ++r)
      for(int c = 0; c < num_cols; ++c)
        if(board[r][c]=='N')
          board[r][c] = 'O';
        else
          board[r][c] = 'X';
    
  }
};
