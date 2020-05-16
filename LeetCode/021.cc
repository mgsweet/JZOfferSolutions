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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        ListNode *tmp;
        while (l1 && l2) {
            tmp = l1->val <= l2->val? l1 : l2;
            if (head == nullptr) {
                head = tmp;
                p = tmp;
            } else {
                p->next = tmp;
                p = p->next;
            }
            if (l1 == tmp) l1 = l1->next;
            else l2 = l2->next;
        }
        p->next = l1 == nullptr ? l2 : l1;
        return head;
    }
};