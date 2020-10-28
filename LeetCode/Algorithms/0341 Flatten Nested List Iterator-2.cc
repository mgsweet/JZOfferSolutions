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
  stack<NestedInteger> my_stack;
  NestedIterator(vector<NestedInteger> &nested_list) {
    for (auto iter = nested_list.rbegin(); iter != nested_list.rend(); ++iter) my_stack.push(*iter);
  }

  int next() {
    int res = my_stack.top().getInteger();
    my_stack.pop();
    return res;
  }

  bool hasNext() {
    while (!my_stack.empty() && !my_stack.top().isInteger()) {
      auto nested_list = my_stack.top().getList();
      my_stack.pop();
      for (auto iter = nested_list.rbegin(); iter != nested_list.rend(); ++iter) my_stack.push(*iter);
    }
    return !my_stack.empty();
  }
};