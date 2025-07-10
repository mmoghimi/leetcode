class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int st = 0;
      int en = nums.size()-1;
      
      if(nums.size() == 0)
        return 0;
      if(target > nums[nums.size()-1])
        return nums.size();
      
      while (st < en) {
        if(target == nums[st]) return st;
        if(target == nums[en]) return en;
          
        if(st + 1 == en) {
          if(target <= nums[st])
            return st;
          else if(target <= nums[en])
            return en;
        }
          
        int mid = (st+en)/2;
        if(nums[mid] > target) {
          en = mid;
        } else
          st = mid;
      }
      return st;
    }
};
