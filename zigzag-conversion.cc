class Solution {
public:
  string convert(string s, int numRows) {
    if(numRows == 1)
      return s;
    
    vector<vector<char>> board(numRows);
    
    char mode = 'D';
    int r = 0;
    for(auto ch: s) {
      if(mode == 'D') {
        board[r].push_back(ch);
        ++r;
        if(r == numRows) {
          if(numRows > 2) mode = 'Z';
          r -= 2;
        }
      } else if(mode == 'Z') {
        board[r].push_back(ch);
        --r;
        if(r == 0)
          mode = 'D';
      }
    }
    
    string res;
    for(auto v: board)
      for(auto ch: v)
        res += ch;
    return res;
  }
};
