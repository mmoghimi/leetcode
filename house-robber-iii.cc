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
map<pair<TreeNode*, bool>, int> mem;
  
int rob(TreeNode* root, bool skip) {
  if(!root)
    return 0;
  pair<TreeNode*, bool> p(root, skip);
  if(mem.find(p) != mem.end())
    return mem[p];
  
  int case1 = 0, case2 = 0, case3 = 0;
  if(!skip) {
    case1 = root->val + (root->right?rob(root->right, true):0) + (root->left?rob(root->left, true):0);
    case2 = (root->right?rob(root->right, false):0) + (root->left?rob(root->left, false):0);
  } else
    case3 = (root->right?rob(root->right, false):0) + (root->left?rob(root->left, false):0);
  
  return mem[p] = max(case1, max(case2, case3));
}
  
int rob(TreeNode* root) {
  return rob(root, false);
}
};
