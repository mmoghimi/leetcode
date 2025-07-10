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
vector<int> inorderTraversal(TreeNode* root) {
  list<TreeNode*> stack;

  TreeNode* node = root;
  
  vector<int> res;
  while(!stack.empty() || node) {
    // cout << (node?node->val:-1) << endl;;
    if(node) {
      stack.push_back(node);
      node = node->left;
    } else {
      node = stack.back();
      stack.pop_back();
      res.push_back(node->val);
      node = node->right;
    }
  }
  return res;
}

vector<int> inorderTraversalRecursive(TreeNode* root) {
  if(!root)
    return vector<int>();
  
  vector<int> res;
  if(root->left) {
    vector<int> v = inorderTraversal(root->left);
    res.insert(res.end(),v.begin(),v.end());
  }
  res.push_back(root->val);
  if(root->right) {
    vector<int> v = inorderTraversal(root->right);
    res.insert(res.end(),v.begin(),v.end());
  }
  return res;
}
};
