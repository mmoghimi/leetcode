class Solution {
public:
    bool f(string& s, string& t) {        
        char m[256] = {0};
        for(int i = 0; i < s.length(); ++i) {
            if(!m[s[i]])
                m[s[i]] = t[i];
            else {
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;

        return f(s, t) && f(t, s);
    }
};
