class Solution {
public:
vector<int> candidates;
vector<vector<int>> results;
  
void combinationSumRecursive(vector<int>& partial, int target) {
  if(target == 0) {
    vector<int> v;
    for(int i = 0; i < partial.size(); ++i)
        for(int k = 0; k < partial[i]; ++k)
          v.push_back(candidates[i]);
    results.push_back(v);
    return;
  }
  
  int number_index = partial.size();
  if(number_index >= candidates.size())
    return;
  
  for(int i = 0; i*candidates[number_index] <= target; ++i) {
    vector<int> new_partial = partial;
    new_partial.push_back(i);
    combinationSumRecursive(new_partial, target-i*candidates[number_index]);
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  this->candidates = candidates;
  vector<int> empty_partial;
  combinationSumRecursive(empty_partial, target);
  return results;
}
};
