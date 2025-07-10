class Solution {
public:
vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> subsets;
  
  for(int i = 0; i < (2<<(nums.size()-1)); ++i) {
    vector<int> v;
    int x = i;
    for(int j = 0; j < nums.size(); ++j) {
      if(x%2) v.push_back(nums[j]);
      x /= 2;
    }
    subsets.push_back(v);
  }
  return subsets;
}
};
