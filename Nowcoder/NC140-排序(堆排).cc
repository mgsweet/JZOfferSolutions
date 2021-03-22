class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    void SiftDown(vector<int> &arr, int index, int last) {
        int max_index = index;
        int c1 = index * 2 + 1;
        int c2 = index * 2 + 2;
        if (c1 < last && arr[c1] > arr[max_index]) max_index = c1;
        if (c2 < last && arr[c2] > arr[max_index]) max_index = c2;
        if (max_index != index) {
            swap(arr[index], arr[max_index]);
            SiftDown(arr, max_index, last);
        }
    }
    
    void BuildHeap(vector<int> &arr) {
        for (int i = arr.size() / 2; i >= 0; --i) SiftDown(arr, i, arr.size());
    }
    
    
    vector<int> MySort(vector<int> &arr) {
        BuildHeap(arr);
        for (int i = 0; i < arr.size(); ++i) {
            swap(arr[0], arr[arr.size() - i - 1]);
            SiftDown(arr, 0, arr.size() - i - 1);
        }
        return arr;
    }
};