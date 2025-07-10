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
int Count(ListNode* head) {
  if(!head)
    return 0;
  int count = 0;
  while(head) {
    head = head->next;
    ++count;
  }
  return count;
}

ListNode* Advance(ListNode* head, int k) {
  for(int i = 0; i < k; ++i)
    head = head->next;
  return head;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if(!headA || !headB)
    return NULL;
  
  int countA = Count(headA);
  int countB = Count(headB);
  
  if(countA > countB)
    headA = Advance(headA, countA-countB);
  else
    headB = Advance(headB, countB-countA);

  while(headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }
  
  return headA;
}
};
