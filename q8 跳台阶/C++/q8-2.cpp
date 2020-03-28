class Solution {
public:
    int jumpFloor(int number) {
        if (number < 1) exit(EXIT_FAILURE);
        
        vector<int> v({1, 2});
        if (number < 3) return v[number - 1];
        
        int result = -1;
        for (int i = 2; i < number; i++) {
            result = v[0] + v[1];
            v[0] = v[1];
            v[1] = result;
        }
        
        return result;
    }
};
