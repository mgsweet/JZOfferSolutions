# Q28 数组中出现次数超过一半的数字

## 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## 题目总结
最简单直接的方法，丢进map中然后逐个计数，然后找到计数大于一半的那个，但问题是需要另开存储空间：
```c
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0)
        return 0;
    map<int, int> myMap;
    for (int num : numbers) {
        if (myMap.find(num) != myMap.end()) {
            myMap[num]++;
        } else {
            myMap[num] = 1;
        }
    }
    for (auto data: myMap) {
        if (data.second > numbers.size() / 2)
            return data.first;
    }
    return 0;
}
```

换一种思维，排序后，数量超过半数的数据，肯定在中位数的位置上，二分法找到中位数最左和最右的位置，右减左即可知道数量，对比是否超过半数。时间复杂度$O(NlogN) + O(LogN) = O(NlogN)$
```c
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0) return 0;
    
    sort(numbers.begin(), numbers.end());
    int mid = numbers.size() / 2;
    int left = findPos(numbers[mid], 0, mid, true, numbers);
    int right = findPos(numbers[mid], mid, numbers.size() - 1, false, numbers);
    
    if (right - left + 1 > numbers.size() / 2)
        return numbers[mid];
    return 0;
}
```
其中`findpos`使用二分查找找出最左最右的位置，其实直接从头计算也没差，因为时间复杂度已经是 $O(NlogN)$ 了，快不了多少。
```c
int findPos(int target, int begin, int end, bool isLeft,
            const vector<int> & numbers) {
    if (begin == end) {
        return begin;
    } else if (begin + 1 == end) {
        if (isLeft) return numbers[begin] == target ? begin : end;
        else return numbers[end] == target ? end : begin;
    }
    int mid = (begin + end) / 2;
    if (numbers[mid] == target) {
        if (isLeft) {
            return findPos(target, begin, mid, isLeft, numbers);
        } else {
            return findPos(target, mid, end, isLeft, numbers);
        }
    } else {
        if (isLeft) {
            return findPos(target, mid + 1, end, isLeft, numbers);
        } else {
            return findPos(target, begin, mid - 1, isLeft, numbers);
        }
    }
}
```

当然也能直接用`find`来做, 但要注意对rfind得到位置的处理。
```c
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
```


