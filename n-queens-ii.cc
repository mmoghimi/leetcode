typedef vector<bool> V;

class Solution {
public:
    // col[i] == ith column is taken
    int count(V& col, V& diag, V& diag2, int row) {
        int n = col.size();
        if(row == n)
            return 1;
        
        int result = 0;
        for(int i = 0; i < n; ++i) {
            if(col[i] || diag[row+i] || diag2[row-i+n])
                continue;
            

            diag[row+i] = true;
            diag2[row-i+n] = true;
            col[i] = true;
            result += count(col, diag, diag2, row+1);
            diag[row+i] = false;
            diag2[row-i+n] = false;
            col[i] = false;

        }
        return result;
    }
    int totalNQueens(int n) {
        V col(n);
        V diag(2*n);
        V diag2(2*n);
        return count(col, diag, diag2, 0);
    }
};