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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *resHead = nullptr, *resP = nullptr;
        int carry = 0;
        while (p1 != nullptr || p2 != nullptr) {
            int x = p1 == nullptr ? 0 : p1->val;
            int y = p2 == nullptr ? 0 : p2->val;
            int sum = x + y + carry;
            carry = sum / 10;
            if (resP == nullptr) {
                resHead = resP = new ListNode(sum % 10);
            } else {
                resP->next = new ListNode(sum % 10);
                resP = resP->next;
            }
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
        }
        if (carry > 0) resP->next = new ListNode(carry);
        return resHead;
    }
};
