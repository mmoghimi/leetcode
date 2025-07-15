class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        sort(words.begin(), words.end());
        do {
            string c;
            for(auto w: words)
                c += w;
            int start = 0;
            while(true) {
                int l = s.find(c, start);
                if(l == -1)
                    break;
                res.push_back(l);
                start = l + 1;
            }
        } while(next_permutation(words.begin(), words.end()));
        return res;
    }
};