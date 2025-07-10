class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> indices(n);
        for(int i = 0; i < k; ++i)
            indices[n-1-i] = 1;

        vector<vector<int>> combinations;
        do {
            vector<int> v;
            for(int i = 0; i < n; ++i)
                if(indices[i])
                    v.push_back(1+i);
            combinations.push_back(v);
        } while(next_permutation(indices.begin(), indices.end()));
        return combinations;
    }
};