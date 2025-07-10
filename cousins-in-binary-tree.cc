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
int findDepth(TreeNode* root, int x, int current_depth=0) {
  if(!root)
    return -1;
  
  if(root->val == x)
    return current_depth;
  else
    return max(findDepth(root->right, x, current_depth+1), 
               findDepth(root->left, x, current_depth+1));
}

bool areSiblings(TreeNode* root, int x, int y) {
  if(!root)
    return false;
  
  if(root->right && root->left && 
     ( (root->right->val == x && root->left->val == y)
     || (root->right->val == y && root->left->val == x) ))
    return true;
  
  if(root->right, areSiblings(root->right, x, y))
    return true;
  if(root->left, areSiblings(root->left, x, y))
    return true;
  return false;
}
  
bool isCousins(TreeNode* root, int x, int y) {
  if(!root)
    return false;
  
  if (areSiblings(root, x, y)) {
    return false;
  }
  
  return findDepth(root, x) == findDepth(root, y);
}
};
