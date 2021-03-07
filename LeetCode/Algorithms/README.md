# LeetCode Solution
Only easy or medium level problem would be consider:)

## Review

[TOC]

### 001 [Two Sum](https://leetcode.com/problems/two-sum)

1. Trading space for speed. Use Hashmap to get an $O(1)$ lookup time complexity.
2. Hashmap in C++ is call `unordered_map`

### 002 [Add Two Numbers](https://leetcode.com/problems/add-two-numbers)

Read the question carefully! First you need to understand what the question is asking!

### 003 [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) 

use `to_string()` to make it easy.

### 005 [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring)

string constructer:`string(const string &s, int pos, int n)`

### 007 [Reverse Integer](https://leetcode.com/problems/reverse-integer) 

1. **Mod** in `int`: $-7 % 10 = -7$ not equeals to 3.
2. Learn to use `#include <limits>` and then use `INT_MAX/INT_MIN` to get the max int or min int.
3. This kind of problem is mainly about overflow.

### 009 [Palindrome Number](https://leetcode.com/problems/palindrome-number)  

1. use `max()` to simplify your code;
2. Use the concept of sliding window.

### 011 [Container With Most Water](https://leetcode.com/problems/container-with-most-water) 

1. Two pointer approach

### 013 [Roman to Integer](https://leetcode.com/problems/roman-to-integer)

1. Use `switch` instead of `unordered_map` to save memory.
2. Think about the question upside down.

### 015 [3SUM](https://leetcode.com/problems/3sum/)

1. Need to avoid writing something like ` i < nums.size() - 2`. Since `nums.size()` is unsigned, 0 - 2 will be a huge number.

### 029 [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/submissions/)

1. `long long` use `labs` to get the absolute value of long long.
2. `^` can use as XOR like `&&` and `||`.



## 56 [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

- The quickest way to use customized compare function in `sort`

  ```c++
  sort(v.begin(), v.end(), [](const vector<int> &v1, const vector<int> &v2){ return v1[0] < v2[0]; };
  ```

  

### 107 [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

1. No need to create pair to record the tree depth if u only want to separate different depth node. Use `nullptr ` !

### 112 [Path Sum](https://leetcode.com/problems/path-sum/)

1. Can use `st` to represent stack;
2. Can directly change the value in the node to record the sum.
3. Better to use `stack st({root})` to initialize the stack.

### 0125 [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

1. use `isalnum()` can check whether a character is alphabet or number, i.e., checks for an alphanumeric character (0-9, A-Z, a-z).
2. use `tolower()` can help get the int number of a lower case, it will only change upper case char.

### 148 [Sort List](https://leetcode.com/problems/sort-list/)

1. Use Mergesort to achieve $O(NlogN)$ time using constant space complexity.

### 172 [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes)

1. The caveat is that 25 has two five in factors, both of which should be counted, while 125 has three, etc.

### 189 [Rotate Array](https://leetcode.com/problems/rotate-array/)

1. Can use reverse array to rotate array.
2. Can use count in the `for` loop to simplify some logic.



### 343 [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

1. `priority_queue` need a `vector` for sort definition:

   ```c++
   priority_queue<int, vector<int>, greater<int> > q;
   // Top is the smaller
   // -1, -1, 2, 3, 4...
   // Same as:
   auto cmp = [](int lhs, int rhs) -> bool {return lhs > rhs;};
   priority_queue<int, vector<int>, decltype(cmp) > q(cmp);
   ```



##378 [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

- The fast way to make a customized comparator for priority_queue:

  ```c++
  auto compare = [](Type node1, Tpye node2){ return node1.attribute > node2.attribute }
  priority_queue<int, vector<Type>, decltype(compare)> q(Type)
  ```

  


### 414 [Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)

- `priority_queue` default is less.
- `priority_queue<int, vector<int>, greater<int>>`: 1, 2, 3, 4, 5 ... (1 is `top()`)



### 438 [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string)

- Idea: sliding window.
- multiset
  - To insert element: `s.insert()`
  - To erase all `value` element:`s.erase(value)`
  - To erase one value element: s.erase(s.find(value)) 

### 454 [4Sum II](https://leetcode.com/problems/4sum-ii/)

1. Use **hash map** can reduce the computational cost sometimes.

### 560 [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

- Sliding window only works on monotone situation. (Need to consider negative number when doing testing)
- `hashmap[undefined] = 0` by default.

### 808 [Soup serving](https://leetcode.com/problems/soup-servings/discuss/121711/C%2B%2BJavaPython-When-N-greater-4800-just-return-1)

- 25ml is annoying, use `N/25 + (N% 25 > 0 ? 1: 0)` to solve;
- You don't need to come out with a bottom up method to use DP, just like the example of Fibonacci sequence, you can use Recursion with memory. `if memo[i][j] != default_val: return memo[i][j]`
- For big N, just check some of the large N and then you will get the idea.
- to use a 2d matrix in a function: `double func(double matrix[][500])` if the matrix is not dynamic allocated. 

