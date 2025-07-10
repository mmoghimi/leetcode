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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(!l1) return l2;
      if(!l2) return l1;
      
      ListNode* list = NULL;
      ListNode* node = NULL;
      
      // list->val = l1->val>l2->val?l1->val:l2->val;
      while(l1 || l2) {
        if(!list)
            node = list = new ListNode(0);
        else {
          node->next = new ListNode(0);
          node = node->next;
        }
        if (!l1) {
          node->val = l2->val;
          l2 = l2->next;
        } else if (!l2) {
          node->val = l1->val;
          l1 = l1->next;
        } else if (l1->val>l2->val) {
          node->val = l2->val;
          l2 = l2->next;
        } else {
          node->val = l1->val;
          l1 = l1->next;
        } 
        
      }
      return list;
    }
};
