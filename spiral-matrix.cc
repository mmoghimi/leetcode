class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> vec;
    if(!matrix.size())
      return vec;
    
    int first_col = 0;
    int last_col = matrix[0].size()-1;
    int first_row = 0;
    int last_row = matrix.size()-1;
    while(first_col <= last_col && first_row <= last_row) {
      if(first_col == last_col && first_row == last_row) {
        vec.push_back(matrix[first_row][first_col]);
        break;
      }
      if(first_row == last_row) {
        for(int c = first_col; c <= last_col; ++c)
          vec.push_back(matrix[first_row][c]);
        break;
      }
      
      if(first_col == last_col) {
        for(int r = first_row; r <= last_row; ++r)
          vec.push_back(matrix[r][first_col]);
        break;
      }
      for(int c = first_col; c < last_col; ++c)
        vec.push_back(matrix[first_row][c]);
      
      for(int r = first_row; r < last_row; ++r)
        vec.push_back(matrix[r][last_col]);

      for(int c = last_col; c > first_col; --c)
        vec.push_back(matrix[last_row][c]);

      for(int r = last_row; r > first_row; --r)
        vec.push_back(matrix[r][first_col]);
      
      ++first_col;
      --last_col;
      ++first_row;
      --last_row;
    }
    return vec;
  }
};
