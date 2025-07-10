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
  int depth_left = 0;
  if(root->left)
    depth_left = maxDepth(root->left);
  int depth_right = 0;
  if(root->right)
    depth_right = maxDepth(root->right);
  return 1+max(depth_right, depth_left);
}

int diameterOfBinaryTree2(TreeNode* root) {
  if(!root)
    return 0;
  int case1 = diameterOfBinaryTree2(root->right);
  int case2 = diameterOfBinaryTree2(root->left);
  int case3 = 1 + maxDepth(root->left) + maxDepth(root->right);
  return max(max(case1, case2), case3);
}
int diameterOfBinaryTree(TreeNode* root) {
  return diameterOfBinaryTree2(root)-1;
}
};
