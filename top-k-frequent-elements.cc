class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> hash;
  for(int i = 0; i < nums.size(); ++i) {
    int x = nums[i];
    if(hash.find(x) == hash.end())
      hash[x] = 1;
    else
      hash[x] += 1;
  }
  
  priority_queue<pair<int, int>> q;
  for(unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
    
    q.push(pair<int, int>(-it->second, it->first));
    if(q.size() > k)
      q.pop();
  }
  vector<int> res;
  while(!q.empty()) {
    res.push_back(q.top().second);
    q.pop();
  }
  return res;
}
};
