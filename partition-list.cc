/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesserHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* lesserTail = lesserHead;
        ListNode* greaterTail = greaterHead;
        
        ListNode* p = head;
        
        while(p) {
            cout << p->val << endl;
            if(p->val < x) {
                lesserTail->next = p;
                lesserTail = p;
            } else {
                greaterTail->next = p;
                greaterTail = p;
            }
            p = p->next;
        }

        lesserTail->next = greaterHead->next;
        greaterTail->next = nullptr;

        cout << "done" << endl;
        return lesserHead->next;
    }
};