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
  typedef pair<TreeNode*, int> Node;
  vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> >ans;
    if (!pRoot) 
    	return ans;
    queue<Node> myQueue;
    myQueue.push(Node(pRoot, 0));
    vector<int> tmp;
    int curr_level = 0;
    while (!myQueue.empty()) {
      Node top = myQueue.front();
      if (curr_level != top.second) {
        curr_level = top.second;
        ans.push_back(tmp);
        tmp.clear();
      }
      tmp.push_back(top.first->val);
      myQueue.pop();
      if (top.first->left) {
        myQueue.push(Node(top.first->left, top.second + 1));
      }
      if (top.first->right) {
        myQueue.push(Node(top.first->right, top.second + 1));
      }
    }
    if (!tmp.empty()) {
      ans.push_back(tmp);
    }
    return ans;
  }
};
