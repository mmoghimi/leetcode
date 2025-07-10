class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(!nums.size())
      return vector<int>();
    
    int n = nums.size();
    vector<int> max_left(n);
    vector<int> max_right(n);
    
    for(int i = 0; i < n; ++i) {
      if(i%k == 0)
        max_left[i] = nums[i];
      else
        max_left[i] = max(max_left[i-1], nums[i]);
    }
    
    max_right[n-1] = nums[n-1];
    for(int i = n-2; i >= 0 ; --i) {
      if(i%k == 0)
        max_right[i] = nums[i];
      else
        max_right[i] = max(max_right[i+1], nums[i]);
    }
    vector<int> res(n-k+1);
    for(int i = 0; i <= n-k; ++i)
      res[i] = max(max_left[i+k-1], max_right[i]);
    
    return res;
  }
};
