class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    
    if(!nums.size())
      return res;
    
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i]!=nums[nums[i]-1]) {
        swap(nums[i], nums[nums[i]-1]);
        --i;
      } 
    
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i]!=i+1)
        res.push_back(nums[i]);
    
    return res;
  }
};
