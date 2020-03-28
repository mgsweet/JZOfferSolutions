class Solution {
public:
    int minNumberInRotateArray(const vector<int> & arr) {
        if (arr.empty()) exit(EXIT_FAILURE);
        
        int lhs = 0;
        int rhs = arr.size() - 1;
        
        while (rhs > lhs) {
            int mid = (rhs + lhs) / 2;
            if (arr[mid] < arr[rhs]) {
                rhs = mid;
            } else if (arr[mid] == arr[rhs]) {
                rhs --;
            } else {
                lhs = mid + 1;
            }
        }
        
        return arr[lhs];
    }
};
