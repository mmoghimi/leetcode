class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> counts;
        ++k;
        k = min(k, (int)nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            if(i-k >= 0)
                counts.erase(nums[i-k]);
            if(counts.find(nums[i]) != counts.end())
                return true;
            counts.insert(nums[i]);
        }
        return false;
    }
};
