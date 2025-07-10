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
ListNode* sortList(ListNode* head) {
  ListNode* node = head;
  int count = 0;
  while(node) {
  	++count;
  	node = node->next;
  }
  ListNode* prev;

  prev = NULL;
  node = head;
  for(int i = 0; i < count/2; ++i) {
  	prev = node;
  	node = node->next;
  }
  // TODO check for termination condition

  prev->next = NULL;
  sortList(head);
  sortList(node);

}
};