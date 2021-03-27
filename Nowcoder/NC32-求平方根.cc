// NC32

class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        if (x <= 0) return 0;
        int l = 1, r = max(x / 2, 46341);
        int mid = 0, tmp = 0;
        while (true) {
            mid = l + (r - l) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                if ((mid + 1) > x / (mid + 1)) return mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};