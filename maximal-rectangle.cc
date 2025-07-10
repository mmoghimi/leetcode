class Solution {
public:
int min(int x, int y) {
  return x<y?x:y;
}
int max(int x, int y) {
  return x>y?x:y;
}
int largestRectangleArea(vector<int>& heights) {
  if(heights.size()==1)
    return heights[0];
  heights.push_back(0);
  heights.insert(heights.begin(), 0);
  
  list<int> stack;
  stack.push_back(0);
  int max_area = 0;
  for(int i = 0; i < heights.size(); ++i) {
    // for(list<int>::iterator it=stack.begin(); it != stack.end(); ++it)
    //     cout << *it << " ";
    //   cout << endl;

    while(heights[i]<heights[stack.back()]) {
      int h = heights[stack.back()]; stack.pop_back();
      max_area = max(max_area, h*(i-1-stack.back()));
    }
    stack.push_back(i);
  }
  return max_area;  
}

int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.size() == 0)
    return 0;
  vector<vector<int>> A(matrix.size(), vector<int>(matrix[0].size(), 0));
  for(int i = 0; i < matrix.size(); ++i) 
    for(int j = 0; j < matrix[0].size(); ++j) {
      if(i == 0)
        A[i][j] = (matrix[i][j] == '1');
      else
        A[i][j] = (matrix[i][j] == '1') * A[i-1][j] + (matrix[i][j] == '1');
    }
  int max_area = 0;
  for (int i = 0; i < matrix.size(); ++i)
    max_area = max(max_area, largestRectangleArea(A[i]));
  
  return max_area;
}
};
