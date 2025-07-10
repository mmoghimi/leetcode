typedef pair<int, int> P;

class Solution {
public:
vector<int> pair_to_vec(P p) {
  vector<int> v(2);
  v[0] = p.first;
  v[1] = p.second;
  return v;
}
  
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<P> intervals_pairs(intervals.size());
  for (int i = 0; i < intervals.size(); ++i)
    intervals_pairs[i] = P(intervals[i][0], intervals[i][1]);
  sort(intervals_pairs.begin(), intervals_pairs.end());
  
  vector<vector<int>> results;
  for(int i = 0; i < intervals_pairs.size(); ++i) {
    if(!results.size()) {
      results.push_back(pair_to_vec(intervals_pairs[i]));
    } else {
      if (intervals_pairs[i].first <= results.back()[1])
        results.back()[1] = max(results.back()[1], intervals_pairs[i].second);
      else
        results.push_back(pair_to_vec(intervals_pairs[i]));
    }
  }
  return results;
}
};
