/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
typedef pair<Node*, int> P;

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        vector<Node*> q;
        q.push_back(root);
        while(q.size()) {
            // fix nexts
            for(int i = 0; i < q.size() - 1; ++i) {
                q[i]->next = q[i+1];
            }
            q[q.size()-1] -> next = NULL;

            vector<Node*> next_q;
            for(int i = 0; i < q.size(); ++i) {
                if(q[i]->left)
                    next_q.push_back(q[i]->left);
                if(q[i]->right)
                    next_q.push_back(q[i]->right);
            }
            q = next_q;
        }
        return root;
    }
};