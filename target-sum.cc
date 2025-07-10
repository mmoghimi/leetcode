class Solution {
public:
int findTargetSumWays(vector<int>& nums, int S) {
  int all_sum = 0;
  for(int i = 0; i < nums.size(); ++i)
    all_sum += nums[i];
  if(S > 1000 || S > all_sum)
    return 0;
  if ((all_sum-S) % 2 == 1)
    return 0;
  
  int mem[1001][21] = {0};
  mem[0][0] = 1;
  for(int i = 0; i < nums.size(); ++i) {
    if(i == 0) {
      mem[nums[i]][0] += 1;
    } else {
      for (int j = 0; j <= (all_sum-S)/2; ++j) {
        // cout << i << " " << j << endl;
        if(mem[j][i-1]) {
          mem[j][i] += mem[j][i-1];
          mem[j+nums[i]][i] += mem[j][i-1];
        }
      }
    }
  }
  
  return mem[(all_sum-S)/2][nums.size()-1];
}
  
int findTargetSumWaysBruteForceTimeLimitExceeded(vector<int>& nums, int S) {
  int n = nums.size();
  int count = 0;
  for(int i = 0; i < (1<<n); ++i) {
    int sum = 0;
    int x = i;
    for(int j = 0; j < n; ++j) {
      if(x&1)
        sum += nums[j];
      else
        sum -= nums[j];
      x = x >> 1;
    }
    if(sum == S) {
      // cout << i << endl;
      ++count;
    }
  }
  return count;
}
};
