class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) return nullptr;
        
        TreeNode* lastNode = nullptr;
        recConvert(pRootOfTree, &lastNode);
        TreeNode* pHead = pRootOfTree;
        while(pHead->left != nullptr) {
            pHead = pHead->left;
        }
        return pHead;
    }
    
    void recConvert(TreeNode* pNode, TreeNode** lastNode) {
        if (pNode == nullptr) return;
            
        if (pNode->left != nullptr) {
            recConvert(pNode->left, lastNode);
        }
        
        if (*lastNode != nullptr) {
            (*lastNode)->right = pNode;
        }
        pNode->left = *lastNode;
        *lastNode = pNode;
        
        if (pNode->right != nullptr) {
            recConvert(pNode->right, lastNode);
        }
    }
};
