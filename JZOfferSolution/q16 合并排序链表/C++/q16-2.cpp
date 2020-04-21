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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* resHead = nullptr;
        ListNode* resPNode = nullptr;
        ListNode* p1Node = pHead1;
        ListNode* p2Node = pHead2;
        ListNode* nextNode = nullptr;
        
        if (pHead1 == nullptr) {
            return pHead2;
        } else if (pHead2 == nullptr) {
            return pHead1;
        }
        
        while(p1Node != nullptr && p2Node != nullptr) {
            if (p1Node->val <= p2Node->val) {
                nextNode = p1Node;
                p1Node = p1Node->next;
            } else {
                nextNode = p2Node;
                p2Node = p2Node->next;
            }
            if (resHead == nullptr) {
                resPNode = resHead = nextNode;
            } else {
                resPNode->next = nextNode;
                resPNode = resPNode->next;
            }
        }
        
        if (p1Node != nullptr) {
            resPNode->next = p1Node;
        }
        
        if (p2Node != nullptr) {
            resPNode->next = p2Node;
        }
        return resHead;
    }
};
