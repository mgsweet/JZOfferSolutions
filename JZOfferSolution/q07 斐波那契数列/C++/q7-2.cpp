class Solution {
public:
    int Fibonacci(int n) {
        if (n < 0) exit(EXIT_FAILURE);
        
        vector<int> v(2, 0);
        v[1] = 1;
        if (n < 2) {
            return v[n];
        }
        int result;
        for (int i = 2; i <= n; i++) {
            result = v[0] + v[1];
            v[0] = v[1];
            v[1] = result;
        }
        return result;
    }
};
