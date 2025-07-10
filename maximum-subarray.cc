class Solution {
public:
int maxSubArray(vector<int>& nums) {
  if(nums.size() == 0)
    return 0;
  if(nums.size() == 1)
    return nums[0];
  
  int st = 0;
  int en = 1;
  int sum = nums[0];
  int max_sum = sum;

  while(st < nums.size() && en <= nums.size()) {
    // for(int i = st; i < en; ++i)
    //   cout << nums[i] << " ";
    // cout << endl;
    if(sum < 0 && en<nums.size()) {
      st = en;
      en = en+1;
      sum = nums[st];
      max_sum = max(max_sum, sum);
    } else if(en<nums.size() && sum + nums[en] > 0) {
      sum += nums[en];
      ++en;
      max_sum = max(max_sum, sum);
    } else {
      st = en;
      en = en+1;
      if(st>=nums.size())
        break;
      sum = nums[st];
      max_sum = max(max_sum, sum);
    }
  }
  return max_sum;
}
};
