/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        while(n-- && fast) fast = fast->next;
        if (fast && n > 0) return nullptr;
        ListNode *slow = head;
        if (!fast) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        } else {
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            ListNode *tmp = slow->next;
            slow->next = slow->next->next;
            delete tmp;
            tmp = nullptr;
        }
        return head;
    }
};