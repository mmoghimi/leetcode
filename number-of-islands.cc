class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if(!grid.size())
      return 0;
    
    typedef pair<int, int> P;
    
    int count = 2;
    vector<vector<int>> board(grid.size(), vector<int>(grid[0].size()));
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[0].size(); ++j) {
        board[i][j] = (grid[i][j] == '1');
      }
  }
    
    
    for(int i = 0; i < board.size(); ++i)
    for(int j = 0; j < board[0].size(); ++j) {
      if(board[i][j] == 1) {
        list<P> stack;
        stack.push_back(P(i, j));
        while(!stack.empty()) {
          P point = stack.back();
          stack.pop_back();
          if (board[point.first][point.second] == 1) {
            board[point.first][point.second] = count;
            int dir_r[4] = {-1, 1, 0, 0};
            int dir_c[4] = {0, 0, 1, -1};
            
            for(int k = 0; k < 4; ++k) {
              int new_r = point.first + dir_r[k];
              int new_c = point.second + dir_c[k];
              if(new_r >= 0 && new_r < board.size() && new_c >= 0 && new_c < board[0].size() && board[new_r][new_c]==1)
                stack.push_front(P(new_r, new_c));
            }
          }
        }
        ++count;
      }
    }
    
    return count-2;
  }
};
