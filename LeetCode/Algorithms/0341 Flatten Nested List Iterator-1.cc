class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
  typedef pair<const vector<NestedInteger>& , int> Node;
  stack<Node> my_stack;
  int tmp;

  NestedIterator(vector<NestedInteger> &nestedList) {
    if (!nestedList.empty()) my_stack.push(Node(nestedList, 0));
  }

  int next() {
    tmp = my_stack.top().first[my_stack.top().second].getInteger();
    ++my_stack.top().second;
    if (my_stack.top().first.size() == my_stack.top().second) my_stack.pop();
    return tmp;
  }

  bool hasNext() {
    while (!my_stack.empty() && !my_stack.top().first[my_stack.top().second].isInteger()) {
      auto &new_list = my_stack.top().first[my_stack.top().second].getList();
      ++my_stack.top().second;
      if (my_stack.top().first.size() == my_stack.top().second) my_stack.pop();
      if (!new_list.empty()) my_stack.push(Node(new_list, 0));
    }
    return !my_stack.empty();
  }
};