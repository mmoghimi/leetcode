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
bool isEqual(TreeNode* s, TreeNode* t) {
  if(!!s^!!t)
    return false;
  if(!s && !t)
    return true;
  if(!!s->left ^ !!t->left)
    return false;
  if(!!s->right ^ !!t->right)
    return false;
  if(s->val!=t->val)
    return false;
  
  return (s->left?isEqual(s->left, t->left): true) && (s->right?isEqual(s->right, t->right): true);
} 
bool isSubtree(TreeNode* s, TreeNode* t) {
  if(!t)
    return true;
  else if(!s)
    return false;
  
  return isEqual(s, t) || (s->left&&isSubtree(s->left, t)) || (s->right&&isSubtree(s->right, t));
    
}
};
