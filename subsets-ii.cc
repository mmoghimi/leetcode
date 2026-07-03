class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> h;
        for(auto x: nums) {
            if(h.count(x))
                ++h[x];
            else
                h[x] = 1;
        }

        int p = 1;
        for(const auto& [_,v]: h)
            p *= v+1;
        
        vector<vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < p; ++i) {
            int x = i;
            vector<int> r;

            for(const auto& [k,v]: h) {
                for (int j = 0; j < x%(v+1); ++j)
                    r.push_back(k);
                x /= v+1;
            }

            res.push_back(r);
        }

        return res;
    }
};
