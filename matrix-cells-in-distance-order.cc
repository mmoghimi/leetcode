class Solution {
public:
    vector<int> makeVec(int r, int c) {
        vector<int> v(2);
        v[0] = r;
        v[1] = c;
        return v;
    }
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        vector<vector<bool>> used(rows, vector<bool>(cols));

        typedef pair<int, int> P;
        list<P> points;
        points.push_back(P(rCenter, cCenter));

        while(res.size() < rows*cols) {
            list<P> new_points;

            while(!points.empty()) {
                int r = points.back().first;
                int c = points.back().second;
                points.pop_back();
                if(used[r][c])
                    continue;

                res.push_back(makeVec(r, c));
                used[r][c] = true;
                
                int dir_r[4] = {0, 0, 1, -1};
                int dir_c[4] = {1, -1, 0, 0};

                for(int k = 0; k < 4; ++k) {
                    int new_r = r + dir_r[k];
                    int new_c = c + dir_c[k];

                    if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && !used[new_r][new_c])
                        new_points.push_back(P(new_r, new_c));
                }
            }
                
            points = new_points;
        }
        return res;
    }
};