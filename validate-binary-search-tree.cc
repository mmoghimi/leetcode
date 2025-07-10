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
bool isValidBST(TreeNode* root, int min_val, int max_val, bool if_min, bool if_max) {
  if(!root)
    return true;
  if(if_min && root->val <= min_val)
    return false;
  if(if_max && root->val >= max_val)
    return false;
  
  return isValidBST(root->left, min_val, (if_max?min(max_val, root->val):root->val), if_min, true)
    && isValidBST(root->right, (if_min?max(min_val, root->val):root->val), max_val, true, if_max);
}
  
bool isValidBST(TreeNode* root) {
  return isValidBST(root, 0, 0, false, false);
}
};






// class Solution {
// public:
// bool isValidBST(TreeNode* root, int min_val, int max_val) {
//   if(!root)
//     return true;
//   if(root->val <= min_val || root->val >= max_val)
//     return false;
  
//   return isValidBST(root->left, min_val, min(max_val, root->val))
//     && isValidBST(root->right, max(min_val, root->val), max_val);
// }
  
// bool isValidBST(TreeNode* root) {
//   return isValidBST(root, INT_MIN, INT_MAX);
// }
// };
