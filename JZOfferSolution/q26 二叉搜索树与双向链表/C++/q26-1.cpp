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
    void counterclockwiseTurn(TreeNode* father, TreeNode* self) {
        if (self->right != nullptr) {
            if (self->right->left != nullptr) {
                clockwiseTurn(self, self->right);
            }
        }
        TreeNode* pNode = self;
        while (pNode->right != nullptr) {
            TreeNode* preNode = pNode;
            pNode = pNode->right;
            pNode->left = preNode;
        }
        pNode->right = father;
        father->left = pNode;
        
        if (self->left != nullptr) counterclockwiseTurn(self, self->left);
    }
    
    void clockwiseTurn(TreeNode* father, TreeNode* self) {
        if (self->left != nullptr) {
            if (self->left->right != nullptr) {
                counterclockwiseTurn(self, self->left);
            }
        }
        TreeNode* pNode = self;
        while (pNode->left != nullptr) {
            TreeNode* preNode = pNode;
            pNode = pNode->left;
            pNode->right = preNode;
        }
        pNode->left = father;
        father->right = pNode;
        
        if (self->right != nullptr) clockwiseTurn(self, self->right);
    }

public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        
        if (pRootOfTree->left != nullptr) {
            counterclockwiseTurn(pRootOfTree, pRootOfTree->left);
        }
        if (pRootOfTree->right != nullptr) {
            clockwiseTurn(pRootOfTree, pRootOfTree->right);
        }
        
        return pNode;
    }
};
