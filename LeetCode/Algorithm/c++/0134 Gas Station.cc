class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty())
            return - 1;
        gas[0] -= cost[0];
        int min_gas = gas[0];
        int min_index = 0;
        for (int i = 1; i < gas.size(); ++i) {
            gas[i] += gas[i - 1] - cost[i];
            if (gas[i] < min_gas) {
                    min_gas = gas[i];
                    min_index = i;
            }
        }    
        return *(gas.end() - 1) < 0 ? -1 : (min_index + 1) % gas.size();
    }
};
