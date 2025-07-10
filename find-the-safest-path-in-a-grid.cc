typedef pair<int, int> P;
class Solution {
public:
    bool isPossible(vector<vector<int>>& safety, int v) {
        
        list<P> stack;

        stack.push_back(P(0, 0));
        int n = safety.size();
        
        if(n == 1)
            return safety[0][0]>=v;
        
        if(safety[0][0] < v)
            return false;

        vector<vector<bool>> reached(n, vector<bool>(n, false));

        while(!stack.empty()) {
            int dir_r[4] = {0, 0, 1, -1};
            int dir_c[4] = {1, -1, 0, 0};

            int r = stack.back().first;
            int c = stack.back().second;

            if(r == n-1 && c == n-1)
                return true;

            stack.pop_back();

            if(reached[r][c])
                continue;
            reached[r][c] = true;
            
            for(int k = 0; k < 4; ++k) {
                int new_r = r + dir_r[k];
                int new_c = c + dir_c[k];

                if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && !reached[new_r][new_c] && safety[new_r][new_c] >= v)
                    stack.push_back(P(new_r, new_c));
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safety (n, vector<int>(n, -1));

        list<P> points;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j]) {
                    points.push_back(P(i, j));
                }
        
        int s = 0;
        while(!points.empty()) {
            list<P> new_points;
            while(!points.empty()) {
                int r = points.back().first;
                int c = points.back().second;
                points.pop_back();

                if(safety[r][c] >= 0) continue;
                safety[r][c] = s;

                int dir_c[4] = {1, -1, 0, 0};
                int dir_r[4] = {0, 0, 1, -1};
                for(int i = 0; i < 4; ++i) {
                    int new_r = r + dir_r[i];
                    int new_c = c + dir_c[i];

                    if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && safety[new_r][new_c] == -1) {
                        new_points.push_back(P(new_r, new_c));
                    }
                }
            }
            points = new_points;
            ++ s;
        }

        if(safety[0][0] == 0)
            return 0;
        
        int low = 0;
        int high = 2*n-1;

        while(high > low + 1) {
            int mid = (low+high) / 2;

            if(isPossible(safety, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        for(int v = high; v >= low; --v)
            if(isPossible(safety, v))
                return v;
        return -2;
    }
};