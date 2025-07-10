#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
      vector<vector<int> > sol;
      sort(nums.begin(), nums.end());
        
      for (int i = 0; i < nums.size()-2; ++i) {
        int l = i + 1;
        int r = nums.size()-1;
        while(l < r) {
          if (nums[i] + nums[r] + nums[l] < 0)
            ++l;
          else if (nums[i] + nums[r] + nums[l] > 0)
            ++r;
          else {
            vector<int> v;
            v.push_back(nums[i]);
            v.push_back(nums[l]);
            v.push_back(nums[r]);
            sol.push_back(v);
            while(l < r && nums[l+1] == nums[l])
              ++l;
            while(l < r && nums[r-1] == nums[r])
              --r;
           } 
           --r;++l;
         }
      }
      
      return sol;
}


int main () {
  vector<int> v;
  //vector<vector<int> > vv = threeSum(v); 
  //for(int i = 0; i < vv.size(); ++i) {
  //      for (int j = 0; j < vv[i].size(); ++j)
  //      	cout << vv[i][j] << " ";
  //      cout << endl;
  //}
  v.push_back(0);
  sort(v.begin(), v.end());
  return 0;
}
