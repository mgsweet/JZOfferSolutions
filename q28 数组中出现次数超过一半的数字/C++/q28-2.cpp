class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0) return 0;
    
    sort(numbers.begin(), numbers.end());
    int mid = numbers.size() / 2;
    int left = find(numbers.begin(), numbers.end(), numbers[mid])
                - numbers.begin();
    int right = find(numbers.rbegin(), numbers.rend(), numbers[mid])
                - numbers.rbegin();
    right = numbers.size() - 1 - right;
    
    if (right - left + 1 > numbers.size() / 2)
        return numbers[mid];
    return 0;
}
};
