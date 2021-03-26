#include <memory>

class Solution {
public:
  /**
   *
   * @param head ListNode类
   * @param n int整型
   * @return ListNode类
   */
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = make_shared<ListNode>(0);
    dummy->next = head;
    ListNode *fast = dummy.get();
    while (n-- && fast) {
      fast = fast->next;
    }
    if (fast && n > 0) return nullptr;
    ListNode *slow = dummy.get();
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    return dummy->next;
  }
};