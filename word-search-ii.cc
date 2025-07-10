class Solution {
public:
bool find(vector<vector<char>>& board, string word, int r, int c) {
  if(!word.length()) return true;
  
  int direction_r[4]={0, 0, -1, 1}; 
  int direction_c[4]={-1, 1, 0, 0};
  
  for(int k = 0; k < 4; ++k) {
    int new_r = r + direction_r[k];
    int new_c = c + direction_c[k];
    
    if(new_r >= 0 && new_r < board.size() &&
      new_c >= 0 && new_c < board[0].size() &&
      word[0] == board[new_r][new_c]) {
      board[new_r][new_c] = 0;
      if(find(board, word.substr(1, word.length()-1), new_r, new_c))
        return true;
      board[new_r][new_c] = word[0];
    }
  }
  return false;
}
    
bool exist(vector<vector<char>>& board, string word) {
  if(!word.length()) return true;
  
  for(int i = 0; i < board.size(); ++i)
    for(int j = 0; j < board[i].size(); ++j) 
      if(board[i][j] == word[0]) {
        board[i][j] = 0;
        if(find(board, word.substr(1, word.length()-1), i, j))
          return true;
        board[i][j] = word[0];
      }
  return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  vector<vector<char>> new_board;
  vector<string> found_words;
  for(int i = 0; i < words.size(); ++i) {
    new_board = board;
    if(exist(new_board, words[i]))
      found_words.push_back(words[i]);
  }
  return found_words;
}
};
