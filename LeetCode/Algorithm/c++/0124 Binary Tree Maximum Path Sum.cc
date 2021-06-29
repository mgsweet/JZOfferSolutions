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
    int reMaxPathSum(TreeNode* root, int &ans) {
        if (!root) return 0;
        int left = reMaxPathSum(root->left, ans);
        int right = reMaxPathSum(root->right, ans);
        int res = root->val;
        if (left > 0) res += left;
        if (right > 0) res += right;
        ans = max(ans, res);
        return root->val + max(left, max(right, 0));
    }
    
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        reMaxPathSum(root, ans);
        return ans;
    }
};