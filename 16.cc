class Solution {
public:
    int abs(int x) {
      return x>0?x:-x;
    }
  
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      
      int best = nums[0] + nums[1] + nums[2];
      for(int i = 0; i+2 < nums.size(); ++i) {
        int l = i+1;
        int r = nums.size()-1;
        
        while (l < r) {
          int sum = nums[i] + nums[r] + nums[l];
          if (abs(sum-target) < abs(best-target))
            best = sum;
          if (sum > target)
            --r;
          else if (sum < target)
            ++l;
          else
            return target;
        }
      }
      return best;
    }
};
