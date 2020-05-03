/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
      ListNode *fast_p = pHead;
      ListNode *low_p = pHead;
      while (1) {
        if (!fast_p || !fast_p->next)
          return nullptr;
        low_p = low_p->next;
        fast_p = fast_p->next->next;
        if (fast_p == low_p)
          break;
      }
      fast_p = pHead;
      while (fast_p != low_p) {
        low_p = low_p->next;
        fast_p = fast_p->next;
      }
      return fast_p;
    }
};
