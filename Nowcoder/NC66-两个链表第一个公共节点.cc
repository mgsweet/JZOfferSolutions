/*
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) :
      val(x), next(NULL) {
  }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        int count1 = 0, count2 = 0;
        ListNode *p = pHead1;
        while (p) {
            ++count1;
            p = p->next;
        }
        p = pHead2;
        while (p) {
            ++count2;
            p = p->next;
        }
        p = pHead1;
        ListNode* p2 = pHead2;
        if (count1 < count2) {
            p = pHead2;
            p2 = pHead1;
        }
        int diff = abs(count1 - count2);
        while(diff--) {
            p = p->next;
        }
        while (p && p2) {
            if (p == p2) {
                return p;
            }
            p = p->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};