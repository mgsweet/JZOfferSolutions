/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
private:
    void cloneWithOutRandom(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* tmpNode = nullptr;
        while (pNode != nullptr) {
            tmpNode = new RandomListNode(pNode->label);
            tmpNode->next = pNode->next;
            pNode->next = tmpNode;
            pNode = tmpNode->next;
        }
    }
    
    void setRandom(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while (pNode != nullptr) {
            if (pNode->random != nullptr) {
                pNode->next->random = pNode->random->next;
            }
            pNode = pNode->next->next;
        }
    }
    
    RandomListNode* separateList(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* copyNode = nullptr;
        RandomListNode* copyHead = pHead == nullptr ? nullptr : pHead->next;
        while (pNode != nullptr) {
            copyNode = pNode->next;
            pNode->next = copyNode->next;
            pNode = pNode->next;
            if (pNode != nullptr) copyNode->next = pNode->next;
        }
        return copyHead;
    }
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        cloneWithOutRandom(pHead);
        setRandom(pHead);
        return separateList(pHead);
    }
};
