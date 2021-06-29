class Solution {
public:
  static int coinChange(vector<int> &coins, int amount) {
    vector<int> memo(amount + 1, -1);
    memo[0] = 0;
    for (int i = 0; i < amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (memo[i] != -1
            && i <= INT_MAX - coins[j]
            && i + coins[j] <= amount
            && (memo[i + coins[j]] == -1
                || memo[i + coins[j]] > memo[i] + 1)) {
          memo[i + coins[j]] = memo[i] + 1;
        }
      }
    }
    return memo[amount];
  }
};