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
        if (!root) return false;
        stack<TreeNode*> st({root});
        TreeNode* top = nullptr;
        while (!st.empty()) {
            top = st.top();
            st.pop();
            if (!top->left && !top->right && top->val == sum) {
                return true;
            }
            if (top->left) {
                top->left->val += top->val;
                st.push(top->left);
            }
            if (top->right) {
                top->right->val += top->val;
                st.push(top->right);
            }
        }
        return false;
    }
};