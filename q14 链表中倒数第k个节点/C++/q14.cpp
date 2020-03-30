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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k == 0) return nullptr;
        
        ListNode* pNode = pListHead;
        ListNode* prekNode = nullptr;
        
        int i = 0;
        while (pNode != nullptr) {
            i++;
            if (i == k) {
                prekNode = pListHead;
            } else if (i > k) {
                prekNode = prekNode->next;
            }
            pNode = pNode->next;
        }
        return prekNode;
    }
};
