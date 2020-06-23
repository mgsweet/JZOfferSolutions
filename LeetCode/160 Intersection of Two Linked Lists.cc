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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count_a = 0, count_b = 0;
        ListNode *p = headA;
        while (p) {
            ++count_a;
            p = p->next;
        }
        p = headB;
        while(p) {
            ++count_b;
            p = p->next;
        }
        if (count_a < count_b) {
            swap(count_a, count_b);
            swap(headA, headB);
        }
        p = headA;
        while (count_a > count_b) {
            p = p->next;
            --count_a;
        }
        ListNode *pa = p, *pb = headB;
        while (count_a && pa != pb) {
            pa = pa->next;
            pb = pb->next;
            --count_a;
        }
        return pa;
    }
};