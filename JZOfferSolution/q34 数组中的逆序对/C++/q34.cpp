class Solution {
private:
    int InversePairsCore(int* data, int* copy, int start, int end) {
        if (start == end) {
            copy[start] = data[start];
            return 0;
        }
        
        int mid = (end + start) / 2;
        
        int left = InversePairsCore(copy, data, start, mid);
        int right = InversePairsCore(copy, data, mid + 1, end);
        
        int i = mid;
        int j = end;
        int copyIndex = end;
        int count = 0;
        
        while(i >= start && j >= mid + 1)
        {
            if (data[i] > data[j]) {
                copy[copyIndex--] = data[i--];
                count = (count + j - mid) % 1000000007;
            } else {
                copy[copyIndex--] = data[j--];
            }
        }
        
        while(i >= start) {
            copy[copyIndex--] = data[i--];
        }
        while (j >= mid + 1) {
            copy[copyIndex--] = data[j--];
        }
        
        return (left + right + count) % 1000000007;
    }
public:
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;
        
        int* clonedData = new int[data.size()];
        int* copy = new int[data.size()];
        
        int i = 0;
        for (auto num : data) {
            clonedData[i] = num;
            copy[i] = num;
            i++;
        }
        
        int count = InversePairsCore(clonedData, copy, 0, data.size() - 1) % 1000000007;
        delete []clonedData;
        delete []copy;
        
        return count;
    }
};
