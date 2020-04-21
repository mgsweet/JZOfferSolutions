/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> myQueue;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        TreeNode* tmpNode;
        myQueue.push(root);
        while(!myQueue.empty()) {
             tmpNode = myQueue.front();
            res.push_back(tmpNode->val);
            if (tmpNode->left) {
                myQueue.push(tmpNode->left);
            }
            if (tmpNode->right) {
                myQueue.push(tmpNode->right);
            }
            myQueue.pop();
        }
        return res;
    }
};
