/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*, int> P;

class Solution {
public:
int CountNodes(TreeNode* root) {
  list<TreeNode*> stack;
  stack.push_back(root);
  int node_counter = 0;

  while(!stack.empty()) {
    ++node_counter;
    TreeNode* node = stack.back();
    stack.pop_back();

    if (node->left)
      stack.push_back(node->left);
    if (node->right)
      stack.push_back(node->right);
  }

  return node_counter;
}
int maxPathSum(TreeNode* root) {
  list<P> stack;
  stack.push_back(P(root, 0));
  int node_counter = 1;

  int node_count = CountNodes(root);

  vector<int> values(node_count);
  vector<vector<int>> neighbors(node_count);

  while(!stack.empty()) {
    TreeNode* node = stack.back().first;
    int node_index = stack.back().second;
    stack.pop_back();

    values[node_index] = node->val;

    if (node->left) {
      stack.push_back(P(node->left, node_counter));
      neighbors[node_index].push_back(node_counter);
      neighbors[node_counter].push_back(node_index);
      ++node_counter;
    }
    if (node->right) {
      stack.push_back(P(node->right, node_counter));
      neighbors[node_index].push_back(node_counter);
      neighbors[node_counter].push_back(node_index);
      ++node_counter;      
    }
  }
  
  // cout << "graph creation finished" << endl;
  
  // for (int i = 0; i < neighbors.size(); ++i) {
  //   for (int j = 0; j < neighbors[i].size(); ++j) {
  //     cout << neighbors[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int max_sum = INT_MIN;

  for(int starting_node = 0; starting_node < node_count; ++starting_node) {
    // cout << "starting_node" << starting_node << endl;
    typedef pair<int, int> PII;
    list<PII> stack;

    stack.push_back(PII(starting_node, values[starting_node]));
    vector<bool> visited(node_count, 0);
    
    while(!stack.empty()) {
      int node_index = stack.back().first;
      int sum = stack.back().second;
      
      stack.pop_back();
      
      if(visited[node_index])
        continue;
      // cout << node_index << " " << sum << endl;
      if(sum > max_sum)
        max_sum = sum;
      visited[node_index] = true;
      
      for (int j = 0; j < neighbors[node_index].size(); ++j)
        stack.push_back(PII(neighbors[node_index][j], sum+values[neighbors[node_index][j]]));
    }
  }

  return max_sum;
}


};
