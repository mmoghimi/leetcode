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
    if(!head)
      return NULL;
    if(!head->next)
      return NULL;
    if(!head->next->next)
      return NULL;
    
    ListNode* fast = head->next->next;
    ListNode* slow = head->next;
    
    while(fast != slow) {
      if(!fast || !fast->next)
        return NULL;
      fast = fast->next->next;
      slow = slow->next;
    }
    
    fast = head;
    while(fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
