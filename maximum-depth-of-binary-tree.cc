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
int maxDepth(TreeNode* root) {
  if(!root)
    return 0;
  int depth_right = 0;
  int depth_left = 0;
  if(root->right)
    depth_right = maxDepth(root->right);
  if(root->left)
    depth_left = maxDepth(root->left);
  return 1+max(depth_right, depth_left);
}
};
