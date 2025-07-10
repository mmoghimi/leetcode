class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> output(nums.size(), 1);
  int product_so_far = 1;
  for(int i = 0; i < nums.size(); ++i) {
    output[i] *= product_so_far;
    product_so_far *= nums[i];
  }
  
  product_so_far = 1;
  for(int i = nums.size()-1; i >= 0; --i) {
    output[i] *= product_so_far;
    product_so_far *= nums[i];
  }

  return output;
}
};
