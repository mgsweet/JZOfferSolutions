class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    if (src == dst) return 0;
    if (flights.empty() || src >= n || dst >= n) return -1;
    vector<int> cur_cost(n, -1);
    cur_cost[src] = 0;
    vector<int> next_cost;
    ++K;
    while (K--) {
      next_cost = cur_cost;
      for (int i = 0; i < flights.size(); ++i) {
        if (cur_cost[flights[i][0]] != -1) {
          if (next_cost[flights[i][1]] == -1) {
            next_cost[flights[i][1]] = cur_cost[flights[i][0]]  + flights[i][2];
          } else {
            next_cost[flights[i][1]] = min(cur_cost[flights[i][0]] + flights[i][2], next_cost[flights[i][1]]);
          }
        }
      }
      cur_cost = next_cost;
    }
    return cur_cost[dst];
  }
};
