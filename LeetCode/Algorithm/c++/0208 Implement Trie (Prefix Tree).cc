struct TrieNode {
  unordered_map<char, TrieNode*> charNodes;
  int count;
  TrieNode(): count(0) {}
};

class Trie {
private:
  TrieNode* root;
public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode()) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *p = root;
    for (int i = 0; i < word.size(); ++i) {
      if (p->charNodes.find(word[i]) == p->charNodes.end()) {
        p->charNodes[word[i]] = new TrieNode();
      }
      p = p->charNodes[word[i]];
    }
    ++p->count;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *p = root;
    for (int i = 0; i < word.size(); ++i) {
      if (p->charNodes.find(word[i]) == p->charNodes.end()) {
        return false;
      }
      p = p ->charNodes[word[i]];
    }
    return p->count > 0;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *p = root;
    for (int i = 0; i < prefix.size(); ++i) {
      if (p->charNodes.find(prefix[i]) == p->charNodes.end()) {
        return false;
      }
      p = p ->charNodes[prefix[i]];
    }
    return true;
  }
};