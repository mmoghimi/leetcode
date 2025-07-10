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
    ListNode* swapPairs(ListNode* head) {
      if(!head || !head->next)
        return head;
        
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      
      ListNode* a;
      ListNode* b;
      ListNode* c;
      ListNode* d;
      
      a = dummy;
      b = head;
      c = head->next;
      
      while (b && c) {
        d = c->next;
        a->next = c;
        c->next = b;
        b->next = d;

        a = b;
        b = d;
        if(!b) break;
        c = b->next;
      }
      return dummy->next;
    }
};
