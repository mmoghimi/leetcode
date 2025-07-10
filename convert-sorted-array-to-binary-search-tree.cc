/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if(end <= start)
      return NULL;
    
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = sortedArrayToBST(nums, start, mid);
    node->right = sortedArrayToBST(nums, mid+1, end);
    return node;
  }
  
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
  }
};
