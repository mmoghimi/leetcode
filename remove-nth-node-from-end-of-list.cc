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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      
      ListNode* first;
      ListNode* second;
      
      first = dummy;
      second = dummy;
      for(int i = 0; i < n; ++i)
        second = second->next;
      while(second->next) {
        second = second->next;
        first = first->next;
      }
      first->next = first->next->next;
      return dummy->next;
    }
};
