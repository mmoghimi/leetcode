class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1)
            return vector<int>{0, 1};

        auto v = grayCode(n-1);
        vector<int> res;
        for(int i = 0; i < v.size(); i+=2) {
            res.push_back(v[i]*2);
            res.push_back(v[i]*2+1);
            res.push_back(v[i+1]*2+1);
            res.push_back(v[i+1]*2);
        }
        return res;
    }
};
