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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode *even_head = head->next;
        ListNode *odd_p = head, *even_p = even_head;
        while (odd_p) {
            if (!even_p || !even_p->next) break;
            odd_p->next = even_p->next;
            odd_p = odd_p->next;
            even_p->next = odd_p->next;
            even_p = even_p->next;
        }
        odd_p->next = even_head;
        return head;
    }
};