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
    bool isAllMatch(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == nullptr) return true;
        else if (pRoot1 == nullptr) return false;
        
        if (pRoot1->val == pRoot2->val) {
            return (isAllMatch(pRoot1->left, pRoot2->left) &&
                    isAllMatch(pRoot1->right, pRoot2->right));
        }
        return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        
        if (pRoot1->val == pRoot2->val) {
            result = isAllMatch(pRoot1, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
};
