class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 计算
   * @param n int整型 数组的长度
   * @param array int整型vector 长度为n的数组
   * @return long长整型
   */
  long long subsequence(int n, vector<int>& array) {
    if (array.empty()) return 0;
    if (array.size() == 1) return max(0, array[0]);
    vector<long long> memo;
    memo[0] = max(array[0], 0);
    memo[1] = max(array[0], max(array[1], 0));
    for (int i = 2; i < array.size(); ++i) {
      if (array[i] <= 0) memo[i] = memo[i - 1];
      else memo[i] = max(memo[i - 2] + array[i], memo[i - 1]);
    }
    return memo[n - 1];
  }
};