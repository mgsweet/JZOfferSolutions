class Solution {
public:
    int jumpFloor(int number) {
        if (number < 0) exit(EXIT_FAILURE);
        vector<int> memo(max(number + 1, 3));
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        for (int i = 3; i <= number; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
        return memo[number];
    }
};