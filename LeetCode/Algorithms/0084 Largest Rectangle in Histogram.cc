class Solution {
public:
  static int largestRectangleArea(vector<int>& heights) {
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> height_stack;
    height_stack.push(0);
    int res = 0;
    for (int i = 1; i < heights.size(); ++i) {
      if (heights[i] < heights[height_stack.top()]) {
        while (heights[height_stack.top()] > heights[i]) {
          int cur_height = heights[height_stack.top()];
          height_stack.pop();
          res = max(res, cur_height * (i - height_stack.top() - 1));
        }
      }
      height_stack.push(i);
    }
    return res;
  }
};
