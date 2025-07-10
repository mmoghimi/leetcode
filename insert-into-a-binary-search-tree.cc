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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      TreeNode* node = root;
      TreeNode* parent = NULL;
      while(node) {
        parent = node;
        if(val > node->val)
          node = node->right;
        else
          node = node->left;
      }
      if(val > parent->val)
          parent->right = new TreeNode(val);
        else
          parent->left = new TreeNode(val);
      return root;
    }
};
