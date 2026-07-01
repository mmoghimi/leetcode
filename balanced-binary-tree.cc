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
    map<TreeNode*, int> c;

    int depth(TreeNode* root) {
        if(!root)
            return 0;

        if (c.find(root) != c.end())
            return c[root];

        return c[root] = 1 + max(depth(root->right), depth(root->left));
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        return depth(root->right) >= depth(root->left) - 1 
            && depth(root->right) <= depth(root->left) + 1
            && isBalanced(root->right)
            && isBalanced(root->left);
    }
};
