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
    ListNode* ReverseList(ListNode* pHead) {
      ListNode* pNode = pHead;
      ListNode* pPrev = nullptr;
      ListNode* pNext;
      while (pNode) {
        pNext = pNode->next;
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
      }
      return pPrev;
    }
};