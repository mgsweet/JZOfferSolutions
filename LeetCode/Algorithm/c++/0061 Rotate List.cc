class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;
    auto dummy = make_shared<ListNode>();
    dummy->next = head;
    ListNode *slow, *fast;
    slow = fast = dummy.get();
    int count = -1;
    while (fast) {
      fast = fast->next;
      ++count;
    }
    k %= count;
    if (k == 0)
      return head;
    fast = dummy.get();
    while (fast && k) {
      fast = fast->next;
      --k;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    head = slow->next;
    fast->next = dummy->next;
    slow->next = nullptr;
    return head;
  }
};