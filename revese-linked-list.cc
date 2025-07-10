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
ListNode* reverseListRecursive(ListNode* head) {
  if(!head->next)
    return head;
  ListNode* next = head->next;
  ListNode* new_head = reverseListRecursive(next);  
  next->next = head;
  return new_head;
}
ListNode* reverseList(ListNode* head) {
  if(!head)
    return NULL;
  ListNode* new_head = reverseListRecursive(head);
  head->next = NULL;
  return new_head;
}
};
