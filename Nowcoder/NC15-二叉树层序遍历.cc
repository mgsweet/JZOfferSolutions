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
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        // write code here
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        bfs.push(nullptr);
        vector<int> tmp;
        while (!bfs.empty()) {
            if (bfs.front() == nullptr) {
                res.push_back(tmp);
                tmp.clear();
                if (bfs.size() > 1 ) bfs.push(nullptr);
            } else {
                tmp.emplace_back(bfs.front()->val);
                if (bfs.front()->left) bfs.push(bfs.front()->left);
                if (bfs.front()->right) bfs.push(bfs.front()->right);
            }
            bfs.pop();
        }
        return res;
    }
};