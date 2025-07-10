class Solution {
public:
int removeElement(vector<int>& nums, int val) {
  int write_index = 0;
  int read_index = 0;
  int len = nums.size();
  while(read_index < len) {
    while(read_index < len && nums[read_index] == val)
      ++read_index;
    if(read_index < len)
      nums[write_index++] = nums[read_index++];
  }
  return write_index;
}
};
