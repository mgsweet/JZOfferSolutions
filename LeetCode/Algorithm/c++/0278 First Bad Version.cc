// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 0) return 0;
        int start = 1;
        int end = n;
        int mid;
        while (start < end) {
            mid = start / 2 + end / 2;
            if (isBadVersion(mid)) {
                if (isBadVersion(mid - 1) == false) 
                    return mid;
                end = mid - 1;
            } else {
                if (isBadVersion(mid + 1)) 
                    return mid + 1;
                start = mid + 1;
            }
        }
        return start;
    }
};