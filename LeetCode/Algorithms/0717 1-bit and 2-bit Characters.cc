class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size()) {
            if (bits[i] == 1) {
                i += 2;
                if (bits.size() <= i) return false;
            } else {
                i += 1;
                if (bits.size() <= i) return true;
            }
        }
        return false;
    }
};