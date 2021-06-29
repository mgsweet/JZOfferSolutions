class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0) return 0;
        vector<int> ugly_nums(n + 1, 0);
        ugly_nums[0] = 1;
        vector<int> prime_i(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            int min_next = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) 
                min_next = min(min_next, ugly_nums[prime_i[j]] * primes[j]);
            ugly_nums[i] = min_next;
            for (int j = 0; j < primes.size(); ++j) {
                while(ugly_nums[prime_i[j]] * primes[j] <= min_next) ++prime_i[j];
            }
        }
        return ugly_nums[n - 1];
    }
};