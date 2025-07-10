class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    if(!nums.size())
      return vector<int>();
    
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] > 0 && nums[i] <= nums.size() && nums[i]!=nums[nums[i]-1]) {
        swap(nums[i], nums[nums[i]-1]);
        --i;
      }
    
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] != i+1)
        res.push_back(i+1);
    return res;
  }
};
