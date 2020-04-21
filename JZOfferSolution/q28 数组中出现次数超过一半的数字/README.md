# Q28 数组中出现次数超过一半的数字

## 题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## 题目总结
1. 记住，找到第k大的数，可以用快排做到$O(N)$的时间复杂度。


### 更多：
最简单直接的方法，丢进map中然后逐个计数，然后找到计数大于一半的那个，时间复杂度为$O(NLogN)$, 空间复杂度为$O(N)$：
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

但其实可以用$O(N)$的时间复杂度和$O(1)$的空间复杂度解决问题，利用快排中的partition去吧比中位数大的全放左边，比中位数大的全放右边，最后检查中位数的个数是否大于总数的一半就好
```c
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0) return 0;
    int mid = numbers.size() >> 1;
    int start = 0;
    int end = numbers.size() - 1;
    int pivot = partition(numbers, start, end);
    while (pivot != mid) {
        if (pivot < mid) {
            start = pivot + 1;
        } else {
            end = pivot - 1;
        }
        pivot = partition(numbers, start, end);
    }
    int result = numbers[mid];
    int count = 0;
    for (int num : numbers) {
        if (result == num) {
            count++;
        }
    }
    return count > mid ? result : 0;
}
```

可是这样改变了数组，最厉害的方法是一个很巧妙的方法，因为要找到一个数比其他数的总数都要大，所以我们可以通过遍历一次数组，保存一个数字和它的次数，次数遇到同一个数字加1，反之减一，为0就更新数字为新的数。
```
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0) return 0;
    int num = numbers[0];
    int count = 1;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] == num) {
            count++;
        } else {
            count--;
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int x : numbers) {
        if (x == num) count++;
    }
    
    return count > (numbers.size() >> 1) ? num : 0;
}
```



