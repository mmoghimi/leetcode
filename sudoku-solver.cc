typedef vector<vector<char>> Board;

class Solution {
public:
    bool checkPossible(Board& board, int i, int j, char c) {
        for(int r = 0; r < 9; ++r)
            if(board[r][j] == c || board[i][r] == c)
                return false;
        
        
        for(int row = (i/3)*3; row < (i/3)*3+3; row ++)
            for(int col = (j/3)*3; col < (j/3)*3+3; col ++)
                if(board[row][col] == c)
                    return false;
        return true;
    }

    bool canSolveSudoku(Board& board, int start_i) {
        int i, j;
        bool dot_found = false;
        for(i = start_i; i < 9; ++i) {
            for(j = 0; j < 9; ++j)
                if (board[i][j] == '.') {
                    dot_found = true;
                    break;
                }
            
            if(dot_found)
                break;
        }
        if (!dot_found)
            return true;
                
        for(char c = '1'; c <= '9'; ++c) {
            if(checkPossible(board, i, j, c)) {
                board[i][j] = c;
                if (canSolveSudoku(board, j==8?i+1:i)) {
                    return true;
                } else {
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(Board& board) {
        canSolveSudoku(board, 0);
    }
};