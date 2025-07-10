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
ListNode* mergeKLists(vector<ListNode*>& lists) {
  if(!lists.size())
    return NULL;
  
  ListNode* dummy = new ListNode(0);
  ListNode* node = dummy;
  
  typedef pair<int, ListNode*> P;
  priority_queue<P> min_heap;
  
  for(int i = 0; i < lists.size(); ++i)
    if(lists[i])
      min_heap.push(P(-lists[i]->val, lists[i]));    
    

  
  while(!min_heap.empty()) {
    node->next = new ListNode(-min_heap.top().first);
    ListNode* x = min_heap.top().second->next;
    min_heap.pop();
    if(x)
      min_heap.push(P(-x->val, x));
    node = node->next;
  }
  return dummy->next;    
}
};
