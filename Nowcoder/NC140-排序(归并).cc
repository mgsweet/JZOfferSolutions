class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    void MergeSort(vector<int> &arr, vector<int> &dst, int start, int end) {
        if (start == end) return;
        int mid = (start + end) / 2;
        MergeSort(dst, arr, start, mid);
        MergeSort(dst, arr, mid + 1, end);
        Merge(arr, dst, start, mid, end);
    }
    
    void Merge(vector<int> &arr, vector<int> &dst, int l, int mid, int r) {
        int i = l, j = mid + 1;
        int k = l;
        while (i <= mid && j <= r) {
            if (arr[i] < arr[j]) dst[k++] = arr[i++];
            else dst[k++] = arr[j++];
        }
        while (i <= mid) dst[k++] = arr[i++];
        while (j <= r) dst[k++] = arr[j++];
    }
    
    vector<int> MySort(vector<int> &arr) {
        vector<int> tmp(arr.begin(), arr.end());
        MergeSort(arr, tmp, 0, arr.size() - 1);
        return tmp;
    }
};