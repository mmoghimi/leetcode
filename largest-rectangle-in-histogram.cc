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
};
