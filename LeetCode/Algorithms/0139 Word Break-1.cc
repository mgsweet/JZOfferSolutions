class Solution {
public:
  struct Node {
    unordered_map<char, Node *> leaves;
    bool is_end;
    Node(): is_end(false) {}
  };

  static bool wordBreak(string s, vector<string>& wordDict) {
    if (wordDict.empty()) return false;
    if (s.empty()) return true;
    Node* root = new Node();
    for (int i = 0; i < wordDict.size(); ++i) {
      Node * p = root;
      for (int j = 0; j < wordDict[i].size(); ++j) {
        if (p->leaves.find(wordDict[i][j]) == p->leaves.end()) {
          p->leaves[wordDict[i][j]] = new Node();
        }
        p = p->leaves[wordDict[i][j]];
      }
      p->is_end = true;
    }
    list<Node *> candidates;
    candidates.push_back(root);
    for (int i = 0; i < s.size(); ++i) {
      bool has_end = false;
      for (auto iter = candidates.begin(); iter != candidates.end(); ++iter) {
        if ((*iter)->leaves.find(s[i]) != (*iter)->leaves.end()) {
          (*iter) = (*iter)->leaves[s[i]];
          if ((*iter)->is_end)
            has_end = true;
        } else {
          iter = candidates.erase(iter);
          iter--;
        }
      }
      if (has_end) candidates.push_back(root);
    }
    for (Node* node: candidates) {
      if (node == root)
        return true;
    }
    return false;
  }
};