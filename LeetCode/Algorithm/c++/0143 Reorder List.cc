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
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        ListNode *tmp;
        while(fast && fast->next) {
            tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        while(fast && slow) {
            tmp = slow->next;
            slow->next = fast;
            slow = tmp;
            tmp = fast->next;
            fast->next = slow;
            fast = tmp;
        }
    }
};