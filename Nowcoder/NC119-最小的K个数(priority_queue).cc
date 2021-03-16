class Solution {
public:
  static vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (input.size() < k) return vector<int>();
    typedef priority_queue<int, vector<int>, greater<int>> MinHeap;
    MinHeap minHeap(input.begin(), input.end());
    vector<int> res;
    while (k--) {
      res.push_back(minHeap.top());
      minHeap.pop();
    }
    return res;
  }
};