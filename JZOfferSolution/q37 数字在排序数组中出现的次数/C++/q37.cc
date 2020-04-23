#include <iostream>
#include <limits>
#include <map>
#include <array>
#include <vector>

using namespace std;

int FindKPos(const vector<int> &data, int k, int start, int end) {
    if (start == end) {
        return data[start] == k ? start : -1;
    }
    int mid = (start + end) / 2;
    if (data[mid] == k) {
        return mid;
    } else if (data[mid] > k) {
        if (mid <= start) {
            return -1;
        }
        return FindKPos(data, k, start, mid - 1);
    } else {
        if (mid >= end) {
            return -1;
        }
        return FindKPos(data, k, mid + 1, end);
    }
}

int FindBorderOfK(const vector<int> &data, int k, int start, int end, bool isLeft) {
    int mid = (start + end) / 2;
    if (data[mid] == k) {
        if (isLeft) {
            if (mid == start || data[mid - 1] != k)
                return mid;
            else
                return FindBorderOfK(data, k, start, mid - 1, isLeft);
        } else {
            if (mid == end || data[mid + 1] != k)
                return mid;
            else
                return FindBorderOfK(data, k, mid + 1, end, isLeft);
        }
    } else {
        if (isLeft) {
            return FindBorderOfK(data, k, mid + 1, end, isLeft);
        } else {
            return FindBorderOfK(data, k, start, mid - 1, isLeft);
        }
    }
}

int GetNumberOfK(const vector<int> &data, int k) {
    int k_pos = FindKPos(data, k, 0, data.size() - 1);
    if (k_pos == -1) {
        cout << "Can not find " << k << endl;
        return 0;
    }
    int left = FindBorderOfK(data, k, 0, k_pos, true);
    int right = FindBorderOfK(data, k, k_pos, data.size() - 1, false);
    return right - left + 1;
}

int main(int argc, const char* argv[]) {
    vector<int> v{1, 2, 2, 2, 2, 3};
    cout << GetNumberOfK(v, 1) << endl;

    return 0;
}
