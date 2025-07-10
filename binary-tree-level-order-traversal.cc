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
vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> res;
  if(!root)
    return res;

  
  typedef pair<TreeNode*, int> P;
  list<P> stack;
  stack.push_back(P(root, 0));
  
  while(!stack.empty()) {
    TreeNode* node = stack.front().first;
    int depth = stack.front().second;
    stack.pop_front();
    if(depth>=res.size())
      res.push_back(vector<int>());
    res[depth].push_back(node->val);
    if(node->left)
      stack.push_back(P(node->left, depth+1));
    if(node->right)
      stack.push_back(P(node->right, depth+1));
  }
  return res;
}
};
