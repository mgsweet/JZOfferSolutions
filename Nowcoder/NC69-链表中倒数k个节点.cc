class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (k < 1) return nullptr;
        ListNode *p = pHead;
        while (p && k) {
            p = p->next;
            --k;
        }
        if (k) return nullptr;
        ListNode *p2 = pHead;
        while (p) {
            p = p->next;
            p2 = p2->next;
        }
        return p2;
    }
};