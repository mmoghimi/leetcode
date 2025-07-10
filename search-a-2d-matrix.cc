class Solution {
public:
    inline int lookup(vector<vector<int>>& matrix, int index) {
        return matrix[index/matrix[0].size()][index%matrix[0].size()];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix.size()*matrix[0].size());
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target, int start_index, int end_index) {
        int mid_index = (start_index + end_index) / 2;
        int n = matrix.size();
        int m = matrix[0].size();

        if(target < lookup(matrix, start_index) || target > lookup(matrix, end_index-1))
            return false;
        
        if (end_index == start_index)
            return false;
        
        if(end_index == start_index + 1)
            return lookup(matrix, start_index) == target;


        if(lookup(matrix, mid_index) > target)
            return searchMatrix(matrix, target, start_index, mid_index);
        else
            return searchMatrix(matrix, target, mid_index, end_index);
    }
};