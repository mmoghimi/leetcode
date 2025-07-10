class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int max_pos = 1;
    int max_neg = 1;
    
    int res = INT_MIN;
    for(int i = 0; i < n; ++i) {
      int new_max_pos = max(nums[i], max(nums[i]*max_pos, nums[i]*max_neg));
      int new_max_neg = min(nums[i], min(nums[i]*max_pos, nums[i]*max_neg));
      max_neg = new_max_neg;
      max_pos = new_max_pos;
      res = max(res, max_pos);
    }
    return res;
  }
};
