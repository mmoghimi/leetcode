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
bool hasCycle(ListNode *head) {
  if(!head || !head->next)
    return false;
  ListNode* node = head;
  while(node) {
    if(!node->next)
      return false;
    ListNode* next_node = node->next;
    node->next = head;
    node = next_node;
    if(node == head)
      return true;
  }
  return false;
}
};
