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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        sum -= root->val;
        if (!root->left && !root->right) return sum == 0;
        bool l_check = false;
        bool r_check = false;
        if (root->left) l_check = hasPathSum(root->left, sum);
        if (root->right) r_check = hasPathSum(root->right, sum);
        return l_check || r_check;
    }
};