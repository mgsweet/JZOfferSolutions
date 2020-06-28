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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fakeHead = new ListNode(0);
        ListNode* pre_node = fakeHead;
        ListNode* next_node = head;
        ListNode* tmp;
        while(next_node) {
            if (next_node->val != val) {
                pre_node->next = next_node;
                pre_node = pre_node->next;
                next_node = next_node->next;
            } else {
                tmp = next_node;
                next_node = next_node->next;
                delete tmp;
            }
        }
        pre_node->next = nullptr;
        return fakeHead->next;
    }
};