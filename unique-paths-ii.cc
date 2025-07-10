class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> D(m, vector<int>(n));

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    D[i][j] = !grid[i][j];
                    continue;
                }

                if(grid[i][j]) {
                    D[i][j] = 0;
                    continue;
                }
                
                if(i > 0)
                    D[i][j] += D[i-1][j];
                
                if(j > 0)
                    D[i][j] += D[i][j-1];

            }
        }        
        return D[m-1][n-1];
    }
};