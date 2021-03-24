class Solution {
public:
    int Partition(vector<int> &a, int l, int r) {
        int pivot = a[l];
        while (l < r) {
            while (l < r && a[r] >= pivot) --r;
            a[l] = a[r];
            while (l < r && a[l] <= pivot) ++l;
            a[r] = a[l];
        }
        a[l] = pivot;
        return l;
    }
    
    int Assist(vector<int> &a, int l, int r, int K) {
        int mid = Partition(a, l, r);
        if (mid == K) return a[mid];
        else if (mid < K) return Assist(a, mid + 1, r, K);
        else return Assist(a, l, mid - 1, K);
    }
    
    int findKth(vector<int> a, int n, int K) {
        return Assist(a, 0, n - 1, n - K);
    }
};