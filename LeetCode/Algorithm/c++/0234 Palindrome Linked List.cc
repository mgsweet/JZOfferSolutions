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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        int size = 0;
        ListNode* p = head;
        while(p) {
            ++size;
            p = p->next;
        }
        if (size == 1) return true;
        int mid = size / 2 - 1;
        p = head;
        while (mid--) {
            p = p->next;
        }
        ListNode *tmp;
        tmp = p; 
        p = p->next;
        tmp->next = nullptr;
        ListNode *pre = nullptr;
        while (p) {
            tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        p = head;
        tmp = pre;
        while (p) {
            if (p->val != tmp->val) {
                return false;
            }
            p = p->next;
            tmp = tmp->next;
        }
        return true;
    }
};