/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void PreOrder(TreeNode* root, vector<int> &output) {
        if (!root) return;
        output.emplace_back(root->val);
        PreOrder(root->left, output);
        PreOrder(root->right, output);
    }
    
    void InOrder(TreeNode* root, vector<int> &output) {
        if (!root) return;
        InOrder(root->left, output);
        output.emplace_back(root->val);
        InOrder(root->right, output);
    }
    
    void PostOrder(TreeNode* root, vector<int> &output) {
        if (!root) return;
        PostOrder(root->left, output);
        PostOrder(root->right, output);
        output.emplace_back(root->val);
    }
    
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<int> pre_output, in_output, post_output;
        PreOrder(root, pre_output);
        InOrder(root, in_output);
        PostOrder(root, post_output);
        vector<vector<int> > res{pre_output, in_output, post_output};
        return res;
    }
};








