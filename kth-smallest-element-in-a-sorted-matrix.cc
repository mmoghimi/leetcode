class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    if(k == matrix[0].size() * matrix.size())
      return matrix[matrix.size()-1][matrix[0].size()-1];
      
    priority_queue<pair<int, pair<int, int>>> heap;
    
    for(int i = 0; i < matrix[0].size(); ++i)
      heap.push(make_pair(-matrix[0][i], make_pair(i, 0)));
    
    int val = INT_MIN;
    for(int i = 0; i < k; ++i) {
      int col_index = heap.top().second.first;
      int row_index = heap.top().second.second;
      val = -heap.top().first;
      heap.pop();
      
      if(row_index != matrix.size()-1)
        heap.push(make_pair(-matrix[row_index+1][col_index], make_pair(col_index, row_index+1)));
    }
    return val;
  }
};
