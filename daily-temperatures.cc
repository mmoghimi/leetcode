class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    list<int> heap;
    vector<int> res(T.size(), 0);
    for(int i = 0; i < T.size(); ++i) {
      while(!heap.empty() && T[i] > T[heap.back()]) {
        res[heap.back()] = i-heap.back();
        heap.pop_back();
      }
      heap.push_back(i);
    }
    return res;
  }
};
