class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) return false;
        if (pushV.empty()) return true;
        
        stack<int> stackData;
        int push_i = 0;
        int pop_i = 0;
        
        while (pop_i < popV.size()) {
            while(push_i < pushV.size() && popV[pop_i] != pushV[push_i]) {
                stackData.push(pushV[push_i++]);
            }
            if (push_i >= pushV.size() || popV[pop_i] != pushV[push_i]) {
                if (!stackData.empty() && stackData.top() != popV[pop_i]) {
                    return false;
                } else {
                    if (!stackData.empty()) stackData.pop();
                }
            }
            
            if (push_i <= pushV.size()) push_i++;
            pop_i++;
        }
        
        return true;
    }
};
