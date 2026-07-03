class Solution {
public:
    vector<int> hist(string s) {
        vector<int> h(26);
        for(char c: s)
            ++h[c-'a'];
        return h;
    }
    bool canConstruct(string ransomNote, string magazine) {
        auto r = hist(ransomNote);
        auto m = hist(magazine);

        for(int i = 0; i < 26; ++i)
            if(r[i] > m[i])
                return false;
        return true;
    }
};
