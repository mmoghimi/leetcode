/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
int countNodes(TreeNode* root) {
  list<TreeNode*> stack;
    stack.push_back(root);
    int node_counter = 0;
    while(!stack.empty()) {
      TreeNode* node = stack.back();
      stack.pop_back();
      ++node_counter;
      if(node->right)
        stack.push_back(node->right);
      if(node->left)
        stack.push_back(node->left);
    }
  return node_counter;
}

vector<vector<int>> serializeToThreeVectors(TreeNode* root) {
  int node_count = countNodes(root);
  vector<vector<int>> vec_rep(3, vector<int>(node_count, 0));
  // cout << "node_count" << node_count << endl;

  list<pair<TreeNode*, int>> stack;
  int node_counter = 0;
  stack.push_back(pair<TreeNode*, int>(root, node_counter));
  ++node_counter;

  while(!stack.empty()) {
    TreeNode* node = stack.back().first;
    int node_index = stack.back().second;
    vec_rep[0][node_index] = node->val;
    stack.pop_back();
    if(node->right) {
      stack.push_back(pair<TreeNode*, int>(node->right, node_counter));
      vec_rep[1][node_index] = node_counter;
      ++node_counter;
    }
    if(node->left) {
      stack.push_back(pair<TreeNode*, int>(node->left, node_counter));
      vec_rep[2][node_index] = node_counter;
      ++node_counter;
    }
  }
  return vec_rep;
}

TreeNode* deserializeFromThreeVectors(vector<vector<int>>& vec_rep) {
  vector<TreeNode*> nodes(vec_rep[0].size());

  for(int i = 0; i < vec_rep[0].size(); ++i)
    nodes[i] = new TreeNode(vec_rep[0][i]);

  for(int i = 0; i < vec_rep[0].size(); ++i) {
    if(vec_rep[1][i])
      nodes[i]->right = nodes[vec_rep[1][i]];
    if(vec_rep[2][i])
      nodes[i]->left = nodes[vec_rep[2][i]];
  }
  return nodes[0];
}

string ThreeVecToString(vector<vector<int>> vec_rep) {
  ostringstream oss;
  oss << vec_rep[0].size();
  for(int i = 0; i < vec_rep[0].size(); ++i)
    for(int j = 0; j < 3; ++j)
      oss << " " << vec_rep[j][i];
  return oss.str();
}

void StringToThreeVec(string s, vector<vector<int>>& vec_rep) {
  istringstream iss(s);
  int n;
  iss >> n;
  vec_rep = vector<vector<int>>(3, vector<int>(n));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < 3; ++j)
      iss >> vec_rep[j][i];  
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  if(!root)
    return "0";
  return ThreeVecToString(serializeToThreeVectors(root));
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  if (data == "0")
    return NULL;
  vector<vector<int>> vec_rep;
  StringToThreeVec(data, vec_rep);
  return deserializeFromThreeVectors(vec_rep);
}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
