class Solution {
public:
void moveZeroes(vector<int>& nums) {
  if(nums.size() <= 1)
    return;
  
  int write_index = 0;
  int read_index = 0;
  while(read_index < nums.size()) {
    while(read_index < nums.size() && nums[read_index] == 0)
      ++read_index;
    if(read_index < nums.size())
      nums[write_index++] = nums[read_index++];
  }
  while(write_index<nums.size())
    nums[write_index++] = 0;
}
};
