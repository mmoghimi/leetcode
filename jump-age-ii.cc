class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>D(n, INT_MAX);
        D[0] = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = max(0, i-1000); j < i; ++j) {
                if(nums[j] >= i-j)
                    D[i] = min(D[i], D[j] + 1);
            }
        }
        return D[n-1];
    }
};