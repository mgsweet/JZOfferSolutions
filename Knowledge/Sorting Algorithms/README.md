# 排序

没有一种排序在任何情况下都是最好的

前7种是比较型算法，后3种是非比较型算法。

[toc]

## 十大排序
实现参考：[各种排序算法总结](https://www.cnblogs.com/luoxn28/p/5296748.html)，[十大经典排序算法](https://www.runoob.com/w3cnote/ten-sorting-algorithm.html)，[浙江大学快速排序课件](https://www.youtube.com/watch?v=qe4kG-K962g)，[浙江大学希尔排序课件](https://www.youtube.com/watch?v=yJjjkfnduiI)，[浙江大学归并排序课件](https://www.youtube.com/watch?v=wNmQYdAYMdM&t=1407s)
### 1.插入排序

思想是，每次从未排序序列中拿一个数，然后插入到已排序队列合适的位置。

缺点是每次插入要多次影响数组

```c++
static void insertSort(vector<Type> & arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
      swap(arr[j - 1], arr[j]);
    }
  }
}
```



### 2.希尔(Shell)排序

希尔排序是插入排序的改进版，解决大范围转移的问题。

最坏情况：$\theta(N^{2})$

主要原因是原始希尔排序使用区间是除二递减的: $D_{k} = D_{k - 1} / 2; D_{0} = length / 2$，由于不互质的问题，可能导致前几次排序不起作用要一直到最后一次间隔为一的插入排序才起作用。

```c++
static void shellSort(vector<Type> & arr) {
  for (int inc = arr.size() / 2; inc > 0; inc /= 2) {
    for (int i = 0; i < arr.size(); i += inc) {
      for (int j = i; j >= inc && arr[j - inc] > arr[j]; j -= inc) {
        swap(arr[j - inc], arr[j]);
      }
    }
  }
}
```

### 3.快速排序

关于实现:

1. “实现得不好，不是一般的囧，是递归的囧” 

2. 快速排序为什么快，主要是每次选定主元并执行完移位后，主元就不需要再动了，而例如在插入排序中，一张新的牌插进来，往往要移动很多个数。

3. 如果有元素正好等于pivot怎么办？（停下来交换比较好）
   1. 停下来交换（坏处是对于一个全等的序列，每轮都要交换$N \over 2$ 次， 但好处是每次的base都停在中间，一共进行$log（N）$次）
   2. 不理它，继续移动指针（好处是对于一个全等序列，每轮不交换但还是判断了$N \over 2$ 次，但要走$N$轮）
4. 对小规模数据，可能还不如插入排序（因为递归），解决方法是可以在程序中定义一个Cutoff的阀值，低于阀值则停止递归，直接简单排序

#### 简单实现

```c++
static int partition(vector<Type> & arr, int lhs, int rhs) {
    // Compared with base every time;
    int baseVal = arr[lhs];
    while (lhs < rhs) {
        while (lhs < rhs && baseVal <= arr[rhs]) {
            rhs--;
        }
        arr[lhs] = arr[rhs];
        while (lhs < rhs && arr[lhs] <= baseVal) {
            lhs++;
        }
        arr[rhs] = arr[lhs];
    }
    // At the end, lhs should be equal to rhs set back the base.
    // It is ok to return whatever lhs or rhs.
    arr[lhs] = baseVal;
    return lhs;
}

static void reQuickSort(vector<Type> & arr, int lhs, int rhs) {
    if (lhs < rhs) {
        int basePos = partition(arr, lhs, rhs);
        reQuickSort(arr, lhs, basePos - 1);
        reQuickSort(arr, basePos + 1, rhs);
    }
}

static void quickSort(vector<Type> & arr) {
    reQuickSort2(arr, 0, arr.size() - 1);
    return;
}
```



#### 考虑阀值和等于的优化

```c++
static Type median3(vector<Type> & arr, int lhs, int rhs) {
    // Let arr[lhs] < arr[center] < arr[rhs]
    int center = (lhs + rhs) / 2;
    if (arr[lhs] > arr[center]) {
        swap(arr[lhs], arr[center]);
    }
    if (arr[center] > arr[rhs]) {
        swap(arr[center], arr[rhs]);
    }
    if (arr[lhs] > arr[center]) {
        swap(arr[lhs], arr[center]);
    }
    // move pivot to arr[rhs - 1]
    swap(arr[center], arr[rhs - 1]);
    // so that we only have to consider arr[lhs + 1] to arr[rhs - 2]
    return arr[rhs - 1];
}

static void reQuickSort(vector<Type> & arr, int lhs, int rhs) {
    const int cutOff = 5;
    if (cutOff <= rhs - lhs) {
        // Partition
        int pivot = median3(arr, lhs, rhs);
        int i = lhs;
        int j = rhs - 1;
        while (1) {
            // When equal, stop
            while (arr[++i] < pivot) {}
            while (arr[--j] > pivot) {}
            if (i < j) {
                swap(arr[i], arr[j]);
            }
            else {
                break;
            }
        }
        swap(arr[i], arr[rhs - 1]);
        reQuickSort(arr, lhs, i - 1);
        reQuickSort(arr, i + 1, rhs);
    } else {
        _insertSort(arr, lhs, rhs);
    }
}

static void quickSort(vector<Type> & arr) {
    reQuickSort(arr, 0, arr.size() - 1);
    return;
}
```

#### 关于主元

1. 随机取pivot？`rand()`不便宜
2. 取头、中、尾的中位数。例如8、12、3的中位数是8

### 4.归并排序
使用分而治之的方法排序

缺点：需要额外空间，需要来回导数据。一般不用于内排序（所有操作都在内存中完成），一般用于外排序。

实现的时候要注意，merge要传入右边结尾（不能单纯用length计算，因为两个需要合并的队列不一定等长）

```c++
static void merge(vector<Type> & arr, vector<Type> & temp,
                  int left, int right, int rightEnd) {
    int leftEnd = right - 1;
    int tmpI = left;
    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left] <= arr[right])
            temp[tmpI++] = arr[left++];
        else
            temp[tmpI++] = arr[right++];
    }
    while (left <= leftEnd) {
        temp[tmpI++] = arr[left++];
    }
    while (right <= rightEnd) {
        temp[tmpI++] = arr[right++];
    }
}

static void mergePass(vector<Type> & arr, vector<Type> & temp, int length) {
    int i = 0;
    for (i = 0; i + 2 * length <= arr.size(); i += 2 * length) {
        merge(arr, temp, i, i + length, i + 2 * length - 1);
    }
    // Solve the odd problem.
    if (i + length < arr.size()) {
        merge(arr, temp, i, i + length, arr.size() - 1);
    } else {
        for (int j = i; j < arr.size(); j++) {
            temp[j] = arr[j];
        }
    }
}

sstatic void mergeSort(vector<Type>& arr) {
    int length = 1;
    vector<Type> temp(arr);
    while (length < arr.size()) {
        mergePass(arr, temp, length);
        length *= 2;
        mergePass(temp, arr, length);
        length *= 2;
    }
}
```

#### 改进增量序列

##### Hibbard增量序列

1. $D_{k} = 2^{k} - 1$ ，相邻元素互质

2. 最快情况：$T = \theta(N^{3/2})$
3. 猜想：$T_{avg} = O(N^{5/4})$

##### Sedgewick增量序列

1. {1, 5, 19, 41, 109, ...}
2. 猜想$T_{avg} = O(N^{7/6}), T_{worst} = O(N^{4 /3})$

### 5. 堆排序
```c++
static void buildHeap(vector<Type> & arr) {
    int lastParent = (arr.size() - 1) / 2;
    for (int i = lastParent; i >= 0; i--) {
        heapify(arr, arr.size(), i);
    }
}

static void heapify(vector<int> & arr, int n, int index) {
    int c1 = index * 2 + 1;
    int c2 = index * 2 + 2;
    int max = index;
    if (c1 < n) {
        max = arr[c1] > arr[max] ? c1 : max;
    }
    if (c2 < n) {
        max = arr[c2] > arr[max] ? c2 : max;
    }
    if (max != index) {
        swap(arr[index], arr[max]);
        heapify(arr, n, max);
    }
}

static void heapSort(vector<Type> & arr) {
    buildHeap(arr);
    for (int i = arr.size() - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

#### 为什么堆排序比快排慢

平均时间上，堆排序的时间常数比快排要大一些，因此通常会慢一些，但是堆排序最差时间也是O(nlogn)的，这点比快排好。

关于 poor use of cache memory，**快排在递归进行部分的排序的时候**，只会访问局部的数据，因此缓存能够更大概率的命中；而堆排序的建堆过程是整个数组各个位置都访问到的，后面则是所有未排序数据各个位置都可能访问到的，所以不利于缓存发挥作用。简单的说就是快排的存取模型的**局部性（locality）**更强，堆排序差一些。

### 6.冒泡排序
重复地走访要排序的数列，一次比较两个元素，大的”泡泡“往上冒，每次循环后当前最大的“泡泡”冒到最顶端。
```c++
static void bubbleSort(vector<Type> & arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### 7.选择排序

是一种简单直观的排序算法，无论什么数据进去都是 O(n²) 的时间复杂度。所以用到它的时候，数据规模越小越好。

唯一的好处可能就是不占用额外的内存空间了吧。

```c++
static void selectSort(vector<Type> & arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            min = arr[min] < arr[j] ? min : j;
        }
        swap(arr[i], arr[min]);
    }
}
```

### 8.基数排序
[基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数](https://www.runoob.com/w3cnote/radix-sort.html)

实现时候在最后一步记得从最后往前排
```c++
static void radixSort(vector<Type>& arr) {
    // Get the max digit
    int max = arr[0];
    for (Type num : arr) {
        max = max > num ? max : num;
    }
    int maxDigit = 0;
    while (max > 0) {
        maxDigit++;
        max /= 10;
    }
    // Sort
    vector<Type> tmp(arr.size(), 0);
    int radix = 1;
    for (int i = 0; i < maxDigit; i++) {
        vector<int> count(10, 0);
        for (Type num : arr) {
            count[(num / radix) % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        for (int j = arr.size() - 1; j >= 0; j--) {
            int k = (arr[j] / radix) % 10;
            tmp[--count[k]] = arr[j];
        }
        arr = tmp;
        radix *= 10;
    }
}
```

### 9.桶排序
先分桶，再排序，这里为了省事，最后排序用了系统快排。。

当输入数据可以均匀分配到每个桶中时最快

当输入的数据被分配到了同一个桶中最慢

其实可能应该用别的数据结构会快一点，但这里
```c++
static void bucketSort(vector<Type>& arr) {
    const int BUCKET_NUM = 10;
    vector<Type> buckets[BUCKET_NUM];
    Type min = arr[0];
    Type max = arr[0];
    // Find the range
    for (Type num : arr) {
        min = min < num ? min : num;
        max = max > num ? max : num;
    }
    int inc = floor((max - min) / BUCKET_NUM) + 1;
    for (Type num : arr) {
        buckets[int((num - min) / inc)].push_back(num);
    }
    arr = vector<Type>();
    for (int i = 0; i < BUCKET_NUM; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        arr.insert(arr.end(), buckets[i].begin(), buckets[i].end());
    }
}
```

### 计数排序
直接丢进间隔为1的桶并统计个数然后按照大小从头输出。如果数据分布及其稀疏的话会大量占用空间。

当然时间复杂度是最低的。

## 时间复杂度和空间复杂度

![sort](../img/sort.png)

## 排序的稳定性分析

排序是否稳定取决于排序是否会调换那些值相等的元素的顺序，例如对于`{1, 2, 3, 2, 4}`, 排完序后第一个`2`依然在第二个`2`前面，则是稳定排序。对于不稳定的排序算法，只要举出一个实例，即可说明它的不稳定性；而对于稳定的排序算法，必须对算法进行分析从而得到稳定的特性。

### 不稳定的排序

1. 选择排序：例如对于序列`{5, 8, 5, 2, 9}`， 我们知道第一遍选择第1个元素5会和2交换，那么原序列中2个5的相对前后顺序就被破坏了，所以选择排序不是一个稳定的排序算法。
2. 快速排序：比如序列为 `{5, 3, 3, 4, 3, 8, 9, 10, 11}`， 现在中枢元素5和3(第5个元素，下标从1开始计)交换就会把元素3的稳定性打乱。
3. 堆排序：有可能第$n/2$个父节点交换把后面一个元素交换过去了，而第$n/2-1$个父节点把后面一个相同的元素没 有交换，那么这2个相同的元素之间的稳定性就被破坏了。所以，堆排序不是稳定的排序算法。
4. 希尔排序：一次插入排序是稳定的，不会改变相同元 素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。

### 稳定的排序

1. 冒泡排序：交换发生在两个元素之间。如果两个元素相等，只要实现的时候不是手贱去交换一下，他们的顺序是不会变的。
2. 插入排序：每次都将后面的数拿来一步步在在排好序的队列中前移，顺序不变。
3. 归并排序：合并过程中我们可以保证如果两个当前元素相等时，我们把处在前面的序列的元素保存在结果序列的前面，这样就保证了稳定性。
4. 基数排序：基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优 先级排序，最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。基数排序基于分别排序，分别收集，所以其是稳定的排序算法。
5. 桶排序：按在队列先后顺序放桶，不会影响原来的顺序。
6. 计数排序：


## 基数排序 vs 计数排序 vs 桶排序
这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异：
1. 基数排序：根据键值的每位数字来分配桶；
2. 计数排序：每个桶只存储单一键值；
3. 桶排序：每个桶存储一定范围的数值；

## sort与qsort的对比
参考博客：[浅谈C++中qsort与sort的使用方法与区别](https://blog.csdn.net/lkn910907/article/details/44085015)

1. 函数形式不一样，sort有二个参数与三个参数版本，默认升序排序，第三个参数可用于指定比较函数。

   qsort：

   ```c++
   void qsort( void *base, size_t num, size_t width, int (__cdecl *compare ) 
   ```
   
   sort：
   ```c++
   template <class RandomAccessIterator>
   void sort ( RandomAccessIterator first, RandomAccessIterator last )；
   template <class RandomAccessIterator, class Compare>
   void sort ( RandomAccessIterator first, RandomAccessIterator last, Compare comp );
   ```
   
2. compare函数的写法不一样，
    qsort的compare函数写法为：
    ```c++
    int compare (const void *elem1, const void *elem2 ) );
    ```
    sort的compare函数返回的是bool值:

3. sort是一个改进版的qsort. std::sort函数优于qsort的一些特点：对大数组采取9项取样，更完全的三路划分算法，更细致的对不同数组大小采用不同方法排序。



## 自己跑了下对比

时间返回的是CPU时钟计时单元（clock tick）数，测的是100000个int数据。

## 结果

冒泡果真蜗牛哎...

| Sort name              | **Time（clock tick）** |
| :--------------------- | :--------------------- |
| Standard sort          | 6030                   |
| My quick sort          | 17658                  |
| My bucket sort         | 18589                  |
| My radix sort          | 19308                  |
| My quick sort (simple) | 20994                  |
| My merge sort          | 29492                  |
| My heap sort           | 45097                  |
| My shell sort          | 28089929               |
| My select sort         | 32799181               |
| My insertion sort      | 33213722               |
| My bubble sort         | 68185322               |




### 测试代码
```c++
template <typename Type>
void checkSort(void (*func)(vector<Type> &),
               const vector<Type> & ran_arr, const vector<Type> & std_arr) {
    vector<int> copy_arr(ran_arr);
    clock_t start, end;
    start = clock();
    func(copy_arr);
    end = clock();
    cout << '\t' << "Time cost:" << end - start << endl;
    if (std_arr == copy_arr) {
        cout << '\t' << "Correct" << endl;
    } else {
        cout << '\t' << "Fail: ";
        for (int num : copy_arr) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    // Create test data
    const int MAX_TEXT_SIZE = 100000;
    vector<int> arr(MAX_TEXT_SIZE);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % MAX_TEXT_SIZE;
    }
    clock_t start, end;
    cout << "Standard sort:" << endl;
    vector<int> std_arr(arr);
    start = clock();
    sort(std_arr.begin(), std_arr.end());
    end = clock();
    cout << '\t' << "Time cost:" << end - start << endl;
    // My sort
    cout << "My quick sort:" << endl;
    checkSort(MySorts<int>::quickSort, arr, std_arr);
    
    cout << "My quick sort2:" << endl;
    checkSort(MySorts<int>::quickSort2, arr, std_arr);
    
    cout << "My bubble sort:" << endl;
    checkSort(MySorts<int>::bubbleSort, arr, std_arr);
    
    cout << "My heap sort:" << endl;
    checkSort(MySorts<int>::heapSort, arr, std_arr);
    
    cout << "My select sort:" << endl;
    checkSort(MySorts<int>::selectSort, arr, std_arr);
    
    cout << "My insertion sort:" << endl;
    checkSort(MySorts<int>::insertSort, arr, std_arr);
    
    cout << "My shell sort:" << endl;
    checkSort(MySorts<int>::shellSort, arr, std_arr);
    
    cout << "My merge sort:" << endl;
    checkSort(MySorts<int>::mergeSort, arr, std_arr);
    
    cout << "My radix sort:" << endl;
    checkSort(MySorts<int>::radixSort, arr, std_arr);
    
    cout << "My bucket sort:" << endl;
    checkSort(MySorts<int>::bucketSort, arr, std_arr);
    
    return 0;
}

```

## std::sort更快的原因
[知无涯之std::sort源码剖析](http://feihu.me/blog/2014/sgi-std-sort/#stdsort%E7%9A%84%E5%AE%9E%E7%8E%B0)
