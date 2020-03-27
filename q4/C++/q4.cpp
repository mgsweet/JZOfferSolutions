/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* root = nullptr;
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
            return root;
        
        root = constructT(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
        
        return root;
    }
    
    TreeNode* constructT(const vector<int>& pre,
                         const vector<int>& vin,
                        int preStart, int preEnd,
                         int vinStart, int vinEnd) {
        if (preStart > preEnd || vinStart > vinEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(pre[preStart]);
            
        for (int i = vinStart; i <= vinEnd; i++) {
            if (pre[preStart] == vin[i]){
                root->left = constructT(pre, vin,
                                        preStart + 1, preStart + i - vinStart,
                                        vinStart, i - 1);
                root->right = constructT(pre, vin,
                                         preStart + i - vinStart + 1, preEnd,
                                         i + 1, vinEnd);
            }
        }
        
        return root;
    }
};
