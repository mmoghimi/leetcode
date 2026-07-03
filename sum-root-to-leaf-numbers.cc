/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* node, int so_far) {
        if(!node)
            return 0;
        
        if(!node->right && !node->left)
            return so_far*10+node->val;

        return sum(node->right, so_far*10+node->val) 
             + sum(node->left, so_far*10+node->val);
    }

    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};
