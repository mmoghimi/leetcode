class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint64_t> ways(target+1);
        ways[0] = 1;
        for(int i = 0; i <= target; ++i)
            for(int x: nums)
                if(x <= i)
                    ways[i] += ways[i-x];

        return ways[target];
    }
};
