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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head, *slow = dummy;
        while (fast && fast->next) {
            slow->next = fast->next;
            fast->next = fast->next->next;
            slow->next->next = fast;
            slow = fast;
            fast = fast->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};