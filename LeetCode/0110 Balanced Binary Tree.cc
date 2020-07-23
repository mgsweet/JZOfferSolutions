/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int checkBalanced(TreeNode* root, bool &balanced) {
        if (root == nullptr || !balanced) return 0;
        int l_depth = checkBalanced(root->left, balanced);
        if (!balanced) return 0;
        int r_depth = checkBalanced(root->right, balanced);
        if (!balanced) return 0;
        balanced = abs(l_depth - r_depth) <= 1;
        return max(l_depth, r_depth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        checkBalanced(root, balanced);
        return balanced;
    }
};