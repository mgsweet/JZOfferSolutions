class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        if (arr.size() < 2) return vector<int>(arr.begin(), arr.end());
        // write code here
        vector<int> res{arr[0]};
        vector<int> max_len{1};
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > *res.rbegin()) {
                res.emplace_back(arr[i]);
                max_len.emplace_back(res.size());
            } else {
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                max_len.emplace_back(pos + 1);
            }
        }
        for (int i = arr.size(), j = res.size(); i >= 0 && j > -1; --i) {
            if (max_len[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};