class Solution {
public:
  static int maxNumberOfBalloons(string text) {
    array<int, 26> arr;
    arr.fill(0);
    for (char c: text) {
      ++arr[c - 'a'];
    }
    int res = INT_MAX;
    for (char c: string("ban")) {
      res = min(arr[c - 'a'], res);
    }
    for (char c: string("lo")) {
      res = min(arr[c - 'a'] / 2, res);
    }
    return res;
  }
};
