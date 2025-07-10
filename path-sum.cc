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
bool hasPathSum(TreeNode* root, int sum) {
  typedef pair<TreeNode*, int> P;
  list<P> stack;
  if(!root)
    return false;
  
  stack.push_back(P(root, root->val));
  while(!stack.empty()) {
    TreeNode* node = stack.back().first;
    int sum_so_far = stack.back().second;
    stack.pop_back();
    
    if(node->right)
      stack.push_back(P(node->right, sum_so_far+node->right->val));
    if(node->left)
      stack.push_back(P(node->left, sum_so_far+node->left->val));
    if(!node->left && !node->right && sum==sum_so_far)
      return true;
  }
  return false;
}
};
