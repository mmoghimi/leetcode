class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        if(k == 1) {
            for(int i = 0; i < n; ++i)
                combinations.push_back(vector<int>(1, i+1));
            return combinations;
        }
        
        list<vector<int>> queue;
        for(int i = 0; i < n; ++i) {
            queue.push_back(vector<int>(1, i+1));
        }

        while(!queue.empty()) {
            vector<int> v = queue.back();
            queue.pop_back();

            for(int i = v[v.size()-1]; i < n; ++i) {
                vector<int> vv = v;
                vv.push_back(i+1);

                if(vv.size() == k)
                    combinations.push_back(vv);
                else
                    queue.push_back(vv);
            }
        }

        return combinations;
    }
};