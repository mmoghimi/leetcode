class Solution {
public:
vector<int> nums;
vector<int> mem;
int rob(int n) {
  if(n == 1)
    return nums[0];
  else if (n <= 0)
    return 0;
  if(mem[n] >= 0)
    return mem[n];
  
  return mem[n] = max(nums[n-1] + rob(n-2), rob(n-1));
}
  
int rob(vector<int>& nums) {
  this->mem = vector<int>(nums.size()+1, -1);
  this->nums = nums;
  return rob(nums.size());
}
};
