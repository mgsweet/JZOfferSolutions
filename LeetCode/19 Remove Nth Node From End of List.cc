/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n < 0 || head == nullptr) return nullptr;
    ListNode *p_fast, *p_slow, *p_fake;
    p_fast = head;
    p_fake = p_slow = new ListNode(0, head);
    while (p_fast != nullptr) {
      if (n == 0) {
        p_slow = p_slow->next;
      } else {
        n--;
      }
      p_fast = p_fast->next;
    }
    if (n == 0) {
      if (head == p_slow->next) {
        head = head->next;
      }
      ListNode* tmp = p_slow->next->next;
      delete p_slow->next;
      p_slow->next = tmp;
    }
    delete p_fake;
    return head;
  }
};