class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
  // key: a1..am sum
  // value: count
  unordered_map<int, int> num_segments;
  num_segments[0] = 1;
  int sum = 0;
  int res = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    
    if(num_segments.find(sum-k) != num_segments.end())
      res += num_segments[sum-k];
    
    if(num_segments.find(sum) == num_segments.end())
      num_segments[sum] = 1;
    else
      num_segments[sum] += 1;
  }
  return res;
}
};
