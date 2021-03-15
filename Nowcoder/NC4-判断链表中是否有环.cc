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
      if (!head || !head->next) return false;
      ListNode *pFast = head->next;
      ListNode *pSlow = head;
      while (pFast && pSlow && pFast->next) {
        if (pFast == pSlow) return true;
        pSlow = pSlow->next;
        pFast = pFast->next->next;
      }
      return false;
    }
};