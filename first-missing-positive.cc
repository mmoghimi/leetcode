class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    if(!nums.size())
      return 1;
    
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] > 0 && nums[i] < nums.size() && nums[i]!=nums[nums[i]-1]) {
        swap(nums[i], nums[nums[i]-1]);
        --i;
      }
    
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] != i+1)
        return i+1;
    return nums.size()+1;
  }
};
