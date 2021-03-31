#include <memory>

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *l, ListNode *r) { return l->val > r->val; };
    priority_queue< ListNode * , vector<ListNode *>, decltype(cmp)> heap(cmp);
    auto dummy = make_shared<ListNode>(0);
    ListNode *p = dummy.get();
    for (auto node_p: lists) {
      if (node_p) heap.push(node_p);
    }
    while (!heap.empty()) {
      p->next = heap.top();
      p = p->next;
      heap.pop();
      if (p->next) heap.push(p->next);
    }
    return dummy->next;
  }
};
