class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> myStack;
        vector<int> result;
        // Reverse List
        ListNode* pNode = head;
        ListNode* preNode = nullptr;
        ListNode* tempNode = nullptr;
        while (pNode != nullptr) {
            tempNode = preNode;
            preNode = pNode;
            pNode = pNode->next;
            preNode->next = tempNode;
        }
        head = preNode;
        // Output
        pNode = head;
        while (pNode != nullptr) {
            result.push_back(pNode->val);
            pNode = pNode->next;
        }
        
        return result;
    }
};
