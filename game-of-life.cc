class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
  for(int i = 0; i < board.size(); ++i)
    for(int j = 0; j < board[i].size(); ++j) {
      int live_cell_count = 0;
      for (int k = -1; k <= 1; ++k) {
        for (int l = -1; l <= 1; ++l) {
          if(k == 0 && l == 0)
            continue;
          
          if(i+k>=0 && i+k < board.size() && j+l>=0 && j+l<board[0].size())
            if(board[i+k][j+l] >= 1)
              ++live_cell_count;
        }
      }
      
      if(board[i][j] >= 1) {
        if (live_cell_count < 2)
          board[i][j] = 2;
        
        if (live_cell_count > 3)
          board[i][j] = 2;
      } else {
        if (live_cell_count == 3)
          board[i][j] = -1;
      }
    }
  
  for(int i = 0; i < board.size(); ++i)
    for(int j = 0; j < board[i].size(); ++j)
      if(board[i][j] == 2)
        board[i][j] = 0;
      else if (board[i][j] == -1)
        board[i][j] = 1;
}
};
