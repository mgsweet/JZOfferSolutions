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
    void assist(TreeNode* root, int &sum, bool isLeft) {
        if (!root) return;
        if (root->left) {
            assist(root->left, sum, true);
        }
        if (root->right) {
            assist(root->right, sum, false);
        }
        if (!root->left && !root->right) {
            if (isLeft) sum += root->val;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        assist(root, sum, false);
        return sum;
    }
};