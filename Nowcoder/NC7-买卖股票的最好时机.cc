class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
      int max_income = 0;
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
          if (prices[i] >= INT_MIN + prices[i - 1])
            max_income = max(max_income, prices[i] - prices[i - 1]);
          prices[i] = prices[i - 1];
        }
      }
      return max_income;
    }
};