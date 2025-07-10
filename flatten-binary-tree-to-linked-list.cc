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
void flatten(TreeNode* root) {
  list<TreeNode*> stack;
  stack.push_back(root);
  TreeNode* dummy = new TreeNode(0);
  TreeNode* last = dummy;
  while(!stack.empty()) {
    TreeNode* node = stack.back();
    stack.pop_back();
    if(!node)
      continue;
    
    if(node->right)
      stack.push_back(node->right);

    if(node->left)
      stack.push_back(node->left);
    
    last->right = node;
    last->left = NULL;
    last = node;
  }
  delete dummy;
}
};

