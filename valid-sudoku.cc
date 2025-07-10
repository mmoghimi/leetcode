class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int r = 0; r < 9; ++r) {
      int hist[10] = {};
      for(int c = 0; c < 9; ++c) {
        char x = board[r][c];
        if(x!='.') {
          if(hist[x-'0'])
            return false;
          else
            hist[x-'0'] = 1;
        }
      }
    }
    
    for(int c = 0; c < 9; ++c) {
      int hist[10] = {};
      for(int r = 0; r < 9; ++r) {
        char x = board[r][c];
        if(x!='.') {
          if(hist[x-'0'])
            return false;
          else
            hist[x-'0'] = 1;
        }
      }
    }
    
    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j) {
        int hist[10] = {};
        for(int r = 0; r < 3; ++r)
          for(int c = 0; c < 3; ++c) {
            char x = board[i*3+r][j*3+c];
            if(x != '.') {
              if(hist[x-'0'])
                return false;
              else
                hist[x-'0'] = 1;
             }
          }
      }
    return true;
  }
};
