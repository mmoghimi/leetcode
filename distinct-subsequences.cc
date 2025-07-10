class Solution {
public:
    vector<vector<int>> D;
    string s;
    string t;
    int f(int a, int b) {
        if (b == t.length())
            return 1;
        if (a == s.length())
            return 0;
        
        if(D[a][b] >= 0)
            return D[a][b];
        
        int res = 0;
        for(int i = a; i < s.length(); ++i) {
            if(s[i] == t[b])
                res += f(i+1, b+1);
        }
        return D[a][b] = res;
    }
    int numDistinct(string s, string t) {
        D = vector<vector<int>>(s.length(), vector<int>(t.length(), -1));
        this->s = s;
        this->t = t;
        return f(0, 0);
    }
};