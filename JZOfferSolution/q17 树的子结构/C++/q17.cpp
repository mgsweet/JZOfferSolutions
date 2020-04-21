/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
private:
    bool isTreeEqual(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr) {
            return true;
        } else if (pRoot1 == nullptr && pRoot2 != nullptr) {
            return false;
        }
        
        if (pRoot1->val == pRoot2->val) {
            return isTreeEqual(pRoot1->left, pRoot2->left)
                && isTreeEqual(pRoot1->right, pRoot2->right);
        } else {
            return false;
        }
    }
    
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        
        if (!isTreeEqual(pRoot1, pRoot2)) {
            return HasSubtree(pRoot1->left, pRoot2)
                || HasSubtree(pRoot1->right, pRoot2);
        } else {
            return true;
        }
    }
};
