class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> myStack;
        vector<int> result;
        
        ListNode* pNode = head;
        while (pNode != nullptr) {
            myStack.push(pNode->val);
            pNode = pNode->next;
        }
        
        while (!myStack.empty()) {
            result.push_back(myStack.top());
            myStack.pop();
        }
        
        return result;
    }
};
