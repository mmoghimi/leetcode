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

bool isMirror(TreeNode* left, TreeNode* right) {
  if(!left != !right)
    return false;
  
  if(!left && !right)
    return true;
  
  if (left->val != right->val)
    return false;
  
  if (!left->left != !right->right || !left->right != !right->left)
    return false;
  
  if (left->left && !isMirror(left->left, right->right))
    return false;
  if (left->right && !isMirror(left->right, right->left))
    return false;
  return true;
}
  
bool isSymmetric(TreeNode* root) {
  if(!root)
    return true;
  return isMirror(root->left, root->right);
}
};
