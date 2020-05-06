class Solution {
public:
  void Insert(int num) {
    if (rhs_.empty() || num < rhs_.top()) lhs_.push(num);
    else rhs_.push(num);
    if (lhs_.size() == rhs_.size() + 2) {
      rhs_.push(lhs_.top());
      lhs_.pop();
    }
    if (lhs_.size() + 1 == rhs_.size()) {
      lhs_.push(rhs_.top());
      rhs_.pop();
    }
  }

  double GetMedian() {
    return lhs_.size() > rhs_.size() ? lhs_.top() : static_cast<double>(lhs_.top() + rhs_.top()) / 2;
  }

private:
  priority_queue<int, vector<int>, less<int> > lhs_;
  priority_queue<int, vector<int>, greater<int> > rhs_;
};