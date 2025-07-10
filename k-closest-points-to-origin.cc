class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    typedef pair<int, int> P;
    priority_queue<P> heap;
    for(int i = 0; i < points.size(); ++i)
      heap.push(P(-(points[i][0]*points[i][0]+points[i][1]*points[i][1]), i));
    
    vector<vector<int>> vec;
    for(int i = 0; i < K; ++i) {
      vec.push_back(points[heap.top().second]);
      heap.pop();
    }
    return vec;
  }
};
