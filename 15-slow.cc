class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      // vector<vector<int>> sol_vec;
      set<vector<int>> sol;
      sort(nums.begin(), nums.end());

      map<int, int> num_count;
      for(int i = 0; i < nums.size(); ++i) {
        if(num_count.find(nums[i]) == num_count.end()) {
          num_count[nums[i]] = 1;
        } else {
          ++ num_count[nums[i]];
        }
      }
      
      if (num_count.find(0) != num_count.end() && num_count[0] >= 3 && num_count.size() == 1) {
        return vector<vector<int> >{{0,0,0}};
      }
      
      for (int i = 0; i < nums.size(); ++i)      
      for (int j = i+1; j < nums.size(); ++j) { 
        if(num_count.find(-(nums[i] + nums[j])) == num_count.end()) continue;
        
        if(-(nums[i] + nums[j]) == nums[i] && num_count[nums[i]] < 2) continue;
        if(-(nums[i] + nums[j]) == nums[j] && num_count[nums[j]] < 2) continue;
        if(nums[i] == 0 && nums[j] == 0 && num_count[0] < 3) continue;
        
        vector<int> s{nums[i], nums[j], -nums[i]-nums[j]};
        sort(s.begin(), s.end());
        if(sol.find(s) == sol.end()) {
          sol.insert(s);
          // sol_vec.push_back(s);
        }
            
      }
      return vector<vector<int> >(sol.begin(), sol.end());
    }
};
