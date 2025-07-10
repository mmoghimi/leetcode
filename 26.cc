class Solution {
public:
int removeDuplicates(vector<int>& nums) {
  if(!nums.size())
    return 0;
  int read_index = 1;
  int write_index = 1;
  
  while(read_index < nums.size()) {
    while(read_index < nums.size() && nums[read_index] == nums[read_index-1])
      ++read_index;
    if (read_index < nums.size())
      nums[write_index++] = nums[read_index++];
  }
  return write_index;
}
};
