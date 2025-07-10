class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s;
        for(int x: nums)
            s.insert(x);

        for(int i = 0; i < moveFrom.size(); ++i) {
            int f = moveFrom[i];
            int t = moveTo[i];

            if(s.find(f) == s.end())
                continue;
            
            s.erase(s.find(f));
            s.insert(t);
        }

        vector<int> res;
        for(auto x: s)
            res.push_back(x);
        return res;
    }
};