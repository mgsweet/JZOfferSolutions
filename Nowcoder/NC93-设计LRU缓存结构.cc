#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

class LRUClass {
public:
  explicit LRUClass(int k) : k_(k) {}

  void set(int key, int val) {
    if (memo.empty()) {
      // Initial
      memo[key] = new Node(key, val);
      head = memo[key];
      tail = memo[key];
    } else if (memo.find(key) != memo.end()) {
      // Modify
      UpdateTail(memo[key]);
      UpdateHead(memo[key]);
      memo[key]->val = val;
    } else {
      // Insert
      Node *new_node = new Node(key, val);
      memo[key] = new_node;
      UpdateHead(memo[key]);
      if (memo.size() > k_) {
        Node *delete_node = memo[tail->key];
        memo.erase(memo.find(tail->key));
        delete_node->prev->next = nullptr;
        tail = delete_node->prev;
        delete delete_node;
      }
    }
  }

  int get(int key) {
    if (memo.find(key) == memo.end()) {
      return -1;
    } else {
      UpdateTail(memo[key]);
      UpdateHead(memo[key]);
      return memo[key]->val;
    }
  }

private:
  struct Node {
    int key, val;
    Node *prev;
    Node *next;

    explicit Node(int k, int v, Node *p = nullptr, Node *n = nullptr) : key(k), val(v), prev(p), next(n) {}

    static void Connect(Node *lhs, Node *rhs) {
      if (lhs) lhs->next = rhs;
      if (rhs) rhs->prev = lhs;
    }
  };

  void UpdateHead(Node *node) {
    if (node != head) {
      Node::Connect(node->prev, node->next);
      node->prev = nullptr;
      Node::Connect(node, head);
      head = node;
    }
  }

  void UpdateTail(Node *node) {
    if (node == tail && node->prev) {
      tail = node->prev;
    }
  }

  int k_;
  unordered_map<int, Node *> memo;
  Node *head;
  Node *tail;
};

class Solution {
public:
  /**
   * lru design
   * @param operators int整型vector<vector<>> the ops
   * @param k int整型 the k
   * @return int整型vector
   */
  static vector<int> LRU(vector<vector<int> > &operators, int k) {
    LRUClass lru(k);
    vector<int> res;
    if (k <= 0) return res;
    for (const auto &oper : operators) {
      if (oper[0] == 1) {
        lru.set(oper[1], oper[2]);
      } else {
        res.emplace_back(lru.get(oper[1]));
      }
    }
    return res;
  }
};