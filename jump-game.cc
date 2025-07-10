class Solution {
public:
bool canJump(vector<int>& nums) {
  vector<bool> is_reachable(nums.size(), false);
  is_reachable[0] = true;
  for(int i = 1; i < nums.size(); ++i) {
    for(int j = i-1; j >= 0; --j)
      if(is_reachable[j] && i-j<=nums[j]) {
        is_reachable[i] = true;
        break;
      }
  }
  
  return is_reachable[nums.size()-1];
}
};
