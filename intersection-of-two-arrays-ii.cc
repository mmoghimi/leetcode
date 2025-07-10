class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hash;
    for(int i = 0; i < nums1.size(); ++i) {
      if(hash.find(nums1[i]) == hash.end())
        hash[nums1[i]] = 1;
      else
        hash[nums1[i]] += 1;
    }
    
    vector<int> res;
    
    for(int i = 0; i < nums2.size(); ++i) {
      if(hash.find(nums2[i]) != hash.end() && hash[nums2[i]] > 0) {
        res.push_back(nums2[i]);
        hash[nums2[i]] -= 1;
      }
      
    }
    return res;
  }
};
