class Solution {
public:
  void print_vec(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i)
      cout << v[i] << " ";
    cout << endl;
  }
    bool permute_inplace(vector<int>& v) {
      int k;
      for(k = v.size()-2; k >= 0; --k)
        if(v[k] < v[k+1])
          break;
      if(k < 0) return false;
      
      int i;
      for(i = v.size()-1; i>=0&&v[i]<v[k]; --i) {}
      // cout << "ki" << " " << k << " " << i << endl;
      
      int tmp = v[i];
      v[i] = v[k];
      v[k] = tmp;
      
      int* begin = (&(v[0]))+(k+1);
      int* end = (&(v[0]))+(v.size());
      reverse(begin, end);
      return true;
    }
  
    vector<vector<int>> permute(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> perms;
      do {
        perms.push_back(nums);
        // print_vec(nums);
      } while(permute_inplace(nums));
      return perms;
    }
};
