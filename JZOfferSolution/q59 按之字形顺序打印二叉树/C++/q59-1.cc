/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    typedef pair<TreeNode*, int> TreeInt;

vector<vector<int> > Print(TreeNode* pRoot) {
    queue<TreeInt> queueData;
    vector<vector<int> > result;
    if (pRoot == nullptr) {
        return result;
    }
    
    queueData.push(TreeInt(pRoot, 0));
    int currentLevel = 0;
    vector<int> currentVec;
    
    while(!queueData.empty()) {
        TreeInt temp = queueData.front();
        if (temp.second > currentLevel) {
            if (currentLevel % 2 == 1) {
                reverse(currentVec.begin(), currentVec.end());
            }
            result.push_back(currentVec);
            currentVec.clear();
            currentLevel++;
        }
        currentVec.push_back(temp.first->val);
        if (temp.first->left != nullptr)
            queueData.push(TreeInt(temp.first->left, temp.second + 1));
        if (temp.first->right != nullptr)
            queueData.push(TreeInt(temp.first->right, temp.second + 1));
        queueData.pop();
    }
    
    if (currentLevel % 2 == 1) {
        reverse(currentVec.begin(), currentVec.end());
    }
    result.push_back(currentVec);
    
    return result;
}
    
};