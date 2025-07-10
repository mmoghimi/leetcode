/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;

        ListNode* node = head;
        while(node) {
            s.insert(node);
            if(s.find(node->next) != s.end())
                return node->next;
            node = node->next;
        }

        return NULL;
    }
};