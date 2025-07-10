class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));

        int r_dir[4] = {0, 1, 0, -1};
        int c_dir[4] = {1, 0, -1, 0};

        int r = 0, c = 0;
        int d = 0;
        int count = 0;

        while(count < n*n) {
            if(v[r][c] == 0)
                v[r][c] = ++count;

            int new_r = r + r_dir[d];
            int new_c = c + c_dir[d];

            if(new_r >= n || new_r < 0 || new_c >= n || new_c < 0 || v[new_r][new_c]) {
                d = (d+1) % 4;
            } else {
                r = new_r;
                c = new_c;
            }
        }
        return v;
    }
};