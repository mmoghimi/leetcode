/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

typedef pair<Node*, Node*> P;

class Solution {
public:
    P Flatten(Node* head) {
        Node* current = head;
        Node* last = NULL;

        while(current) {
            if(current->child) {
                Node* next = current->next;
                P p = Flatten(current->child);
                current->child = NULL;

                if(p.first)
                    p.first->prev = current;
                current->next = p.first;

                if(p.second)
                    p.second->next = next;
                if(next)
                    next->prev = p.second;
            }

            if(!current->next)
                last = current;
            current = current->next;
        }
        return P(head, last); 
    }

    Node* flatten(Node* head) {
        if(!head)
            return head;

        return Flatten(head).first;
    }
};