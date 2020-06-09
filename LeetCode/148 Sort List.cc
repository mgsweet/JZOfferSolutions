class Solution {
public:
  ListNode *merge(ListNode *p1, ListNode *p2) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tmp = dummy;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val < p2->val) {
        tmp->next = p1;
        tmp = tmp->next;
        p1 = p1->next;
      } else {
        tmp->next = p2;
        tmp = tmp->next;
        p2 = p2->next;
      }
    }
    if (p1) tmp->next = p1;
    if (p2) tmp->next = p2;
    return dummy->next;
  }

  ListNode *mergeSort(ListNode *head, int n) {
    if (n <= 1) return head;
    ListNode *head1, *head2;
    head1 = head2 = head;
    // Go to position (n/2 - 1), so that we can separate the list into two list (both end with nullptr).
    for (int i = 0; i < n / 2 - 1; ++i) {
      head2 = head2->next;
    }
    ListNode *tmp = head2;
    head2 = head2->next;
    tmp->next = nullptr;
    return merge(mergeSort(head1, n / 2), mergeSort(head2, n - n / 2));
  }

  ListNode *sortList(ListNode *head) {
    ListNode *count_p = head;
    int count = 0;
    while (count_p != nullptr) {
      ++count;
      count_p = count_p->next;
    }
    return mergeSort(head, count);
  }
};