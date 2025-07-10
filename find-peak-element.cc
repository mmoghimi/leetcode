class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int st = 0;
    int en = nums.size()-1;
    while(en>st) {
      int mid = (st+en)/2;

      if(nums[mid] < nums[mid+1])
        st = mid+1;
      else
        en = mid;
    }
    return st;
  }
};
