/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> hash;
    Node* node = head;
    while(node) {
      hash[node] = new Node(node->val);
      node = node->next;
    }
    
    node = head;
    while(node) {
      hash[node]->next = hash[node->next];
      hash[node]->random = hash[node->random];
      node = node->next;
    }
    return hash[head];
  }
};
