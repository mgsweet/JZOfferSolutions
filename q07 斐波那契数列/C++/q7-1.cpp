class Solution {
public:
    int Fibonacci(int n) {
        if (n < 0) exit(EXIT_FAILURE);
        
        vector<int> arr({0, 1});
        
        if (n < 2) {
            return arr[n];
        } else {
            for (unsigned int i = 2; i <= n; i++) {
                arr.push_back(arr[i - 1] + arr[i - 2]);
            }
            return arr[n];
        }
    }
};
