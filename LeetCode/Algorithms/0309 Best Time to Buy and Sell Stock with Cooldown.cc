class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int hasStoreSell = 0;
    int hasStoreDoNothing = -prices[0];
    int noStoreBuy = -prices[0];
    int noStoreDoNoting = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int tmp_hasStoreSell = hasStoreSell;
      hasStoreSell = prices[i] + max(hasStoreDoNothing, noStoreBuy);
      hasStoreDoNothing = max(hasStoreDoNothing, noStoreBuy);
      noStoreBuy = noStoreDoNoting - prices[i];
      noStoreDoNoting = max(tmp_hasStoreSell, noStoreDoNoting);
    }
    return max(hasStoreSell, noStoreDoNoting);
  }
};