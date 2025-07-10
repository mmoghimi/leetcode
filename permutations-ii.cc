class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        do {
            results.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return results;
    }
};