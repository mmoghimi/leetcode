class Solution {
public:
    vector<vector<int>> D;

    bool is_all_stars(string& p, int m) {
        for(int i = 0; i < m; ++i)
            if(p[i] != '*')
                return false;
        return true;
    }
    bool isMatch(string& s, string& p, int n, int m) {
        if(n == 0 && m == 0)
            return true;
        
        if(n == 0)
            return is_all_stars(p, m);
        
        if(m == 0)
            return false;
        
        if(D[n][m] >= 0)
            return D[n][m];
        
        if(p[m-1] == '?')
            return D[n][m] = isMatch(s, p, n-1, m-1);
        
        if(p[m-1] == '*') {
            bool res = false;

            for(int i = 0; i <= n; ++i)
                if(isMatch(s, p, i, m-1))
                    res = true;

            return D[n][m] = res;
        }

        return D[n][m] = ((s[n-1] == p[m-1]) && isMatch(s, p, n-1, m-1));
    }

    bool isMatch(string s, string p) {
        D = vector<vector<int>> (s.length()+1, vector<int>(p.length()+1, -1));
        return isMatch(s, p, s.length(), p.length());
    }
};