class Solution {
public:
int longestConsecutive(vector<int>& nums) {
  unordered_set<int> hash;
  for(int i = 0; i < nums.size(); ++i)
    hash.insert(nums[i]);
  int max_count = 0;
  for(int i = 0; i < nums.size(); ++i) {
    if(hash.find(nums[i]) == hash.end())
      continue;
    
    int count_neg = 0, count_pos = 0;
    for(int j = nums[i]-1; hash.find(j)!=hash.end(); --j)
      ++count_neg;
    for(int j = nums[i]+1; hash.find(j)!=hash.end(); ++j)
      ++count_pos;
    int count = count_neg+count_pos+1;
    if(max_count < count)
      max_count = count;
    
    for(int j = nums[i]-count_neg; j <= nums[i]+count_pos; ++j)
      hash.erase(j);
  }

  return max_count;
}
};
