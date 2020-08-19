class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m, n, i, j;
        int imin, imax, halfPoint;
        double maxOfLeft, minOfRight;
        //保证nums1长度短于nums2  
        if (nums1.size() > nums2.size()) {
            vector<int> tem_v(nums1);
            nums1 = nums2;
            nums2 = tem_v;
        }
        m = nums1.size();
        n = nums2.size();
        imin = 0;
        imax = m;
        while (imin <= imax) {
            i = imin + imax / 2;
            j = (m + n + 1)/2 - i;
            if (i > 0 && nums1[i - 1] > nums2[j]) {
                imax--;
            } else if (i < m && nums2[j - 1] >  nums1[i]) {
                imin++;
            } else {
                if (i == 0) maxOfLeft = nums2[j - 1];
                else if (j == 0) maxOfLeft = nums1[i - 1];
                else maxOfLeft = max(nums1[i-1], nums2[j-1]);
                
                if ((m + n) % 2 == 1) return maxOfLeft;
                
                if (i == m) minOfRight = nums2[j];
                else if (j == n) minOfRight = nums1[i];
                else minOfRight = min(nums1[i], nums2[j]);
                
                return (minOfRight + maxOfLeft) / 2;
            }         
        }
        return 0;
    }
};