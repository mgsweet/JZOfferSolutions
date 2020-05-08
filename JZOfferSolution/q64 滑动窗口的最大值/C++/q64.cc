class Solution {
public:
  static vector<int> maxInWindows(const vector<int>& num, unsigned int size)
  {
    vector<int> ans;
    if (size < 0) return ans;
    deque<int> myDeque;
    for (int i = 0; i < num.size(); ++i) {
      // Step 1, Since all the number in the queue that less than the new one would be no use in the future, pop them.
      while (myDeque.size() && num[myDeque.back()] < num[i])
        myDeque.pop_back();
      // Step 2, For number which is outside of the window, we cannot use them now.
      // Be careful of the type of "size", which is unsigned int. Do not use subtract on a unsigned int.
      while (myDeque.size() && myDeque.front() + size <= i)
        myDeque.pop_front();
      // Step 3, push the new value into the queue, it should be done after step 1 and 2, Because the first two step
      // ensure the front of the queue is the biggest number.
      myDeque.push_back(i);
      if (i >= size - 1)
        ans.push_back(num[myDeque.front()]);
    }
    return ans;
  }
};