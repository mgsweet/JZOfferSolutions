/*
 struct ListNode {
 int val;
 struct ListNode *next;
 ListNode(int x) :
 val(x), next(NULL) {
 }
 };*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *p_head1,
                                  ListNode *p_head2) {
        int len1 = 0, len2 = 0;
        ListNode *p_node1 = p_head1;
        ListNode *p_node2 = p_head2;
        while (p_node1) {
            p_node1 = p_node1->next;
            ++len1;
        }
        while (p_node2) {
            p_node2 = p_node2->next;
            ++len2;
        }
        p_node1 = p_head1;
        p_node2 = p_head2;
        if (len1 < len2) {
            swap(len1, len2);
            swap(p_node1, p_node2);
        }
        int sub = len1 - len2;
        while (sub) {
            --sub;
            p_node1 = p_node1->next;
        }
        while(p_node1 && p_node2) {
            if (p_node1 == p_node2) return p_node1;
            p_node1 = p_node1->next;
            p_node2 = p_node2->next;
        }
        return nullptr;
    }
};
