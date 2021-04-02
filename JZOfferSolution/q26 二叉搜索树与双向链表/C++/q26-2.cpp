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
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        return ReConvert(pRootOfTree, nullptr);
    }
    
    TreeNode* ReConvert(TreeNode* root, TreeNode *link_to) {
        if (!root) return link_to;
        TreeNode *lp = ReConvert(root->left, root);
        TreeNode *rp = ReConvert(root->right, link_to);
        root->right = rp;
        if (rp) rp->left = root;
        return lp;
    }
};