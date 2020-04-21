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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNode = pHead;
        ListNode* pTmp = nullptr;
        ListNode* preNode = nullptr;
        
        while (pNode) {
            preNode = pNode;
            pNode = pNode->next;
            preNode->next = pTmp;
            pTmp = preNode;
        }
        
        return preNode;
    }
};
