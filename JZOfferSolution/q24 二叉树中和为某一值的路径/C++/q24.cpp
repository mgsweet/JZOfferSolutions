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
    void reFindPath(TreeNode* root, int expectNumber,
                    int currentSum, vector<int> & assStack,
                   vector<vector<int> > & res) {
        assStack.push_back(root->val);
        currentSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (currentSum == expectNumber)
                res.push_back(assStack);
        } else {
            if (root->left != nullptr
                && root->left->val + currentSum <= expectNumber) {
                reFindPath(root->left, expectNumber, currentSum, assStack, res);
            }
            if (root->right != nullptr
                && root->right->val + currentSum <= expectNumber) {
                reFindPath(root->right, expectNumber, currentSum, assStack, res);
            }
        }
        currentSum -= root->val;
        assStack.pop_back();
    }
    
    bool static cmp(vector<int> v1, vector<int> v2) {
        return v1.size() > v2.size();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> assStack;
        if (root == nullptr) return res;
        reFindPath(root, expectNumber, 0, assStack, res);
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};
