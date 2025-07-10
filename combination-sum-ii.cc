class Solution {
public:
  unordered_set<string> res_set;
  string vec_to_string(vector<int> v) {
    ostringstream oss;
    sort(v.begin(), v.end());
    for(int i: v)
      oss << i << ",";
    return oss.str();
  }
  vector<vector<int>> res;
  void combinationSum2Recursive(const vector<int>& candidates_left, int target, const vector<int>& sol_so_far) {
    if(!target) {
      if(res_set.find(vec_to_string(sol_so_far)) == res_set.end()) {
        res.push_back(sol_so_far);
        res_set.insert(vec_to_string(sol_so_far));
      }
      return;
    }
    
    for(int ii = 0; ii < candidates_left.size(); ++ii) {
      int i = candidates_left[ii];
      if(i <= target) {
        auto new_sol = sol_so_far;
        new_sol.push_back(i);
        auto new_candidates_left = candidates_left;
        new_candidates_left.erase(new_candidates_left.begin()+ii);
        
        combinationSum2Recursive(new_candidates_left, target-i, new_sol);
      }
    }
  }
  
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    combinationSum2Recursive(candidates, target, vector<int>());
    return res;
  }
};
