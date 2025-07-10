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
int result;
// map<TreeNode*, int> mem;
// int max(int x, int y) {
//   return x>y?x:y;
// }
int maxSum(TreeNode* root) {
  if(!root) return 0;
  // map<TreeNode*, int>::iterator it = mem.find(root);
  // if(it!=mem.end()) return it->second;
  int left_sum = (maxSum(root->left));
  int right_sum = (maxSum(root->right));
  if(left_sum < 0) left_sum = 0;
  if(right_sum < 0) right_sum = 0;
  
  if(left_sum + right_sum + root->val > result)
    result = left_sum + right_sum + root->val;
  // return mem[root] = root->val + max(left_sum, right_sum);
  return root->val + max(left_sum, right_sum);
}
  
int maxPathSum(TreeNode* root) {
  if(!root) return 0;
  
  result = INT_MIN;
  maxSum(root);
  return result;
}


};
