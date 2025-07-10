class Solution {
public:
  void swap(int& x, int& y) {
    x = x^y;
    y = x^y;
    x = x^y;
  }
  
  void rotate(vector<int>& nums, int k) {
    if(nums.size() <= 1)
      return;
    k %= nums.size();
    // // for(int j = 0; j < k%nums.size(); ++j)
    // //   for(int i = nums.size()-1; i >= 1; --i)
    // //     swap(nums[i], nums[i-1]);
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
  }
};
