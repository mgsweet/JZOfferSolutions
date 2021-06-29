class LRUCache {
private:
  struct Node {
    int key, val;
    Node *pre, *next;
    Node(int k, int v): key(k), val(v) {}
  };
  int capacity_;
  unordered_map<int, Node*> data;
  Node *first, *last;
  void connect(Node *lhs, Node *rhs) {
    lhs->next = rhs;
    rhs->pre = lhs;
  }

public:
  LRUCache(int capacity): capacity_(capacity) {
    first = new Node(-1, -1);
    last = new Node(-1, -1);
    first->next = last;
    last->pre = first;
  }

  int get(int key) {
    if (data.find(key) != data.end())  {
      connect(data[key]->pre, data[key]->next);
      connect(last->pre, data[key]);
      connect(data[key], last);
      return data[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (data.find(key) == data.end())  {
      data[key] = new Node(key, value);
    } else {
      data[key]->val = value;
      connect(data[key]->pre, data[key]->next);
    }
    connect(last->pre, data[key]);
    connect(data[key], last);
    if (data.size() > capacity_) {
      data.erase(first->next->key);
      Node* tmp = first->next;
      connect(first, first->next->next);
      delete tmp;
    }
  }
};