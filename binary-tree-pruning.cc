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
  bool pruneMe(TreeNode* root) {
    if(!root)
      return true;
    
    bool pruned_left = pruneMe(root->left);
    if(pruned_left)
      root->left = NULL;
    
    bool pruned_right = pruneMe(root->right);
    if(pruned_right)
      root->right = NULL;

    if(root->val == 1)
      return false;
    
    return pruned_right && pruned_left;
  }
  
  TreeNode* pruneTree(TreeNode* root) {
    if(pruneMe(root))
      return NULL;
    else
      return root;
  }
  
};
