class Solution {
public:
    void Inverse_pair_core(vector<int> &data, vector<int> &tmp_data,
                       int start, int end, int &inverse_count) {
        if (start == end) {
            data[start] = tmp_data[start];
            return;
        }
        int mid = (start + end) / 2;
        Inverse_pair_core(tmp_data, data, start, mid, inverse_count);
        Inverse_pair_core(tmp_data, data, mid + 1, end, inverse_count);
        int i = mid; int j = end;
        int k = end;
        while (i >= start || j >= mid + 1) {
            if (i >= start && j >= mid + 1) {
                if (tmp_data[i] > tmp_data[j]) {
                    data[k--] = tmp_data[i--];
                    inverse_count = (inverse_count + j - mid) % 1000000007;
                } else if (tmp_data[i] < tmp_data[j]) {
                    data[k--] = tmp_data[j--];
                } else {
                    cout << "err" << endl;
                }
            } else if (i < start) {
                data[k--] = tmp_data[j--];
            } else if (j < mid + 1) {
                data[k--] = tmp_data[i--];
            }
        }
    }

    int InversePairs(const vector<int> &data) {
        if (data.empty()) return 0;
        vector<int> data_copy = data;
        vector<int> tmp_data = data_copy;
        int inverse_count = 0;
        Inverse_pair_core(data_copy, tmp_data, 0, data_copy.size() - 1, inverse_count);
        return inverse_count;
    }
};