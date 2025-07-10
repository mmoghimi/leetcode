class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size())
            return false;

        for(int st = 0; st < n-1; ++st) {
            bool same = true;
            for(int i = 0; i < n; ++i)
                if(s[i] != goal[(st+i)%n]) {
                    same = false;
                    break;
                }
            if(same)
                return true;
        }

        return false;
    }
};