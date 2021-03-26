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
    void GetMaxDiff(TreeNode* root, int &res, int max_p, int min_p) {
        if (!root) return;
        max_p = max(max_p, root->val);
        min_p = min(min_p, root->val);
        res = max(res, max_p - min_p);
        GetMaxDiff(root->left, res, max_p, min_p);
        GetMaxDiff(root->right, res, max_p, min_p);
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        GetMaxDiff(root, res, INT_MIN, INT_MAX);
        return res;
    }
};