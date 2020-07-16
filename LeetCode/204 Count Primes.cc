class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> primes(n - 2, true);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (primes[i - 2] == false) continue;
            count++;
            for (int j = 2; i * j < n; ++j) {
                primes[i * j - 2] = false;
            }
        }
        return count;
    }
};