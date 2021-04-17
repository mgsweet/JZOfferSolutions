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
    bool ReDelNodes(vector<TreeNode*> &forest, TreeNode *root, vector<int> &to_delete) {
        if (!root) return false;
        
        bool is_l_delete_node = ReDelNodes(forest, root->left, to_delete);
        if (is_l_delete_node) 
            root->left = nullptr;
        
        bool is_r_delete_node = ReDelNodes(forest, root->right, to_delete);
        if (is_r_delete_node) 
            root->right = nullptr;
        
        for (auto val: to_delete) {
            if (val == root->val) {
                if (root->left) forest.push_back(root->left);
                if (root->right) forest.push_back(root->right);
                delete root;
                return true;
            }
        }
        
        return false;
    }
    
    
    vector<TreeNode*> delNodes(TreeNode *root, vector<int> &to_delete) {
        vector<TreeNode*> forest;
        bool is_root_delete_node = ReDelNodes(forest, root, to_delete);
        if (!is_root_delete_node) forest.push_back(root);
        return forest;
    }
};