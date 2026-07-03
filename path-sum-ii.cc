
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        
        if(!root->left && !root->right && targetSum==root->val)
            return {{root->val}};
        
        vector<vector<int>> res;

        if(root->left) {
            auto r = pathSum(root->left, targetSum-root->val);
            for(auto s: r) {
                s.insert(s.begin(), root->val);
                res.push_back(s);
            }
        }
        if(root->right) {
            auto r = pathSum(root->right, targetSum-root->val);
            for(auto s: r) {
                s.insert(s.begin(), root->val);
                res.push_back(s);
            }
        }
        return res;
    }
};
