class Solution {
public:
    int D[2001] = {0};
    bool isPalindrome(string& s, int st, int en) {
        for(int i = 0; i < (en-st)/2; ++i) {
            if(s[st+i] != s[en-1-i])
                return false;
        }
        return true;
    }
    int minCut(string& s, int n) {
        if(n <= 1)
            return 0;

        if(D[n])
            return D[n];

        if(isPalindrome(s, 0, n))
            return 0;
        
        int res = n-1;
        for(int i = 1; i < n; ++i) {
            if(isPalindrome(s, i, n))
                res = min(res, minCut(s, i) + 1);
        }

        return D[n] = res;
    }
    int minCut(string s) {
        D[0] = 0;
        D[1] = 0;
        return minCut(s, s.length());
    }
};
