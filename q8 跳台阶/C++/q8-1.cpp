class Solution {
public:
    int jumpFloor(int n) {
        if (n < 0) exit(EXIT_FAILURE);
        vector<int> arr({0, 1, 2});
        if (n < 3) {
            return arr[n];
        } else {
            for (unsigned int i = 3; i <= n; i++) {
                arr.push_back(arr[i - 1] + arr[i - 2]);
            }
            return arr[n];
        }
    }
};
