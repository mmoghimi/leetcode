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
  unordered_map<TreeNode*, int> mem_count;
  int count(TreeNode* root) {
    if(!root)
      return 0;
    if(mem_count.find(root) != mem_count.end())
      return mem_count[root];

    return mem_count[root] = 1 + (root->left?count(root->left):0) + (root->right?count(root->right):0);
  }
  
  int kthSmallest(TreeNode* root, int k) {
    // cout << root << " " << k << endl;
    
    if(count(root->left) == k - 1)
      return root->val;
    
    if(count(root->left) < k-1)
      return kthSmallest(root->right, k-1-count(root->left));
    else //count(root->left) > k-1
      return kthSmallest(root->left, k);
      
  }
};
