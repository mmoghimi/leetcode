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
void printList(ListNode* head) {
  ListNode* node = head;
  while(node) {
    cout << node << " " << node->val << endl;
    node = node->next;
  }
  cout << endl;
}
bool isPalindrome(ListNode* head) {
  if(!head)
    return true;
  
  int count = 1;
  ListNode* node = head;
  while(node->next) {
    node = node->next;
    ++count;
  }
  
  if(count <= 1) return true;
  
  if(count % 2 == 1) {
    ListNode* node = head;
    for(int i = 0; i < count/2-1; ++i)
      node = node->next;
    node->next = node->next->next;
  }
  
  // printList(head);
  
  //reverse half;
  ListNode* prev = NULL;
  node = head;
  ListNode* next = node->next;
  for(int i = 0; i < count/2-1; ++i) {
    node->next = prev;
    prev = node;
    node = next;
    next = next->next;
  }
  node->next = prev;
  ListNode* node2 = next;
  while(true) {
    // cout << node->val << " " << node2->val << node << " " << node2 << endl;
    if(node == NULL && node2 == NULL)
      return true;
    if(node->val != node2->val)
      return false;
    node = node->next;
    node2 = node2->next;
  }
  return true;
}
};
