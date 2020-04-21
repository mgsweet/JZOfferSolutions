class Solution {
private:
    int partition(vector<int> & arr, int lhs, int rhs) {
        int base = arr[lhs];
        while (lhs < rhs) {
            while (lhs < rhs && arr[rhs] >= base) {
                rhs--;
            }
            arr[lhs] = arr[rhs];
            while (lhs < rhs && arr[lhs] <= base) {
                lhs++;
            }
            arr[rhs] = arr[lhs];
        }
        arr[lhs] = base;
        return lhs;
    }
    
    void KSmallestSort(vector<int> & arr, int lhs, int rhs, int k) {
        if (lhs >= rhs) return;
        int index = partition(arr, lhs, rhs);
        if (index > k) {
            KSmallestSort(arr, lhs, index - 1, k);
        } else if (index < k) {
            KSmallestSort(arr, index + 1, rhs, k);
        } else {
            return;
        }
    }
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k <= 0) {
            return vector<int>();
        }
        KSmallestSort(input, 0, input.size() - 1, k);
        vector<int> res(input.begin(), input.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};
