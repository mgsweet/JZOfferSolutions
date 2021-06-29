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
private:
    int AssistFunc(TreeNode *root, int &tilt_sum) {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = AssistFunc(root->left, tilt_sum);
        int right_sum = AssistFunc(root->right, tilt_sum);
        tilt_sum += abs(left_sum - right_sum);
        return root->val + left_sum + right_sum;
    }
public:
    int findTilt(TreeNode *root) {
        int tilt_sum = 0;
        AssistFunc(root, tilt_sum);
        return tilt_sum;
    }
};