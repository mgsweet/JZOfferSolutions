class Solution {
public:
    int GetTreeDepth(TreeNode* pRoot, bool &is_balance) {
        if (pRoot == nullptr || is_balance == false) return 0;
        int lhs = (GetTreeDepth(pRoot->left, is_balance));
        int rhs = (GetTreeDepth(pRoot->right, is_balance));
        if (abs(rhs - lhs) > 1) {
            is_balance = false;
            return 0;
        }
        return max(lhs, rhs) + 1;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool ans = true;
        GetTreeDepth(pRoot, ans);
        return ans;
    }
};
