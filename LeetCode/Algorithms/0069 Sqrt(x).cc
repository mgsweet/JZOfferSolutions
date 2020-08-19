class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        if(x == 2) return 1;
        int begin = 0, end = x, mid = end/2;
        while(begin <= end){
            if(x/mid >= mid && x/(mid+1) < (mid+1)) return mid;
            if (x/mid < mid) end = mid -1;
            else begin = mid + 1;
            mid = (begin + end) / 2;
        }
        return (int) end;
    }
};