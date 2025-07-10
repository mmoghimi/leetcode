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
int pathSumInc(TreeNode* root, int sum) {
  int count = 0;
  if(!root)
    return sum==0;
  if(sum == root->val)
    count += 1;
  if(root->right)
    count += pathSumInc(root->right, sum-root->val);
  if(root->left)
    count += pathSumInc(root->left, sum-root->val);
  return count;
}
int pathSumExc(TreeNode* root, int sum) {
  int count = 0;
  if(!root)
    return sum==0;
  if(root->right)
    count += pathSum(root->right, sum);
  if(root->left)
    count += pathSum(root->left, sum);
  return count;
}
  
int pathSum(TreeNode* root, int sum) {
  if(!root) 
    return 0;
  return pathSumInc(root, sum) + pathSumExc(root, sum);
}
};
