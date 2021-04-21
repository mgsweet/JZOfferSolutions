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
    void reRightSideView(vector<int> &res, TreeNode* root, int level) {
        if (!root) return;
        if (res.size() < level) res.push_back(root->val);
        reRightSideView(res, root->right, level + 1);
        reRightSideView(res, root->left, level + 1);
    }
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        reRightSideView(res, root, 1);
        return res;
    }
};