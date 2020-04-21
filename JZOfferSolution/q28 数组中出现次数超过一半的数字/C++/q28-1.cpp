class Solution {
private:
    int partition(vector<int> & arr, int lhs, int rhs) {
        int base = arr[lhs];
        while (lhs < rhs) {
            while(lhs < rhs && arr[rhs] >= base) {
                rhs--;
            }
            arr[lhs] = arr[rhs];
            while(lhs < rhs && arr[lhs] <= base) {
                lhs++;
            }
            arr[rhs] = arr[lhs];
        }
        arr[lhs] = base;
        return lhs;
    }
    
    void quicksortK(vector<int> & arr, int lhs, int rhs, int K) {
        if (lhs < rhs) {
            int base = partition(arr, lhs, rhs);
            if (base > K) quicksortK(arr, lhs, base - 1, K);
            else if (base < K) quicksortK(arr, base + 1, rhs, K);
            else return;
        }
    }
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        vector<int> clonedArr = numbers;
        quicksortK(clonedArr, 0, clonedArr.size() - 1, clonedArr.size() / 2);
        
        int middle = clonedArr[clonedArr.size() / 2];
        int count = 0;
        for (auto num : clonedArr) {
            if (num == middle) {
                count++;
            }
        }
        if (count > clonedArr.size() / 2) {
            return middle;
        }
        return 0;
    }
};
