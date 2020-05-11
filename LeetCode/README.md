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

### 011[Container With Most Water](https://leetcode.com/problems/container-with-most-water) 

1. Two pointer approach

### 013 [Roman to Integer](https://leetcode.com/problems/roman-to-integer)

1. Use `switch` instead of `unordered_map` to save memory.
2. Think about the question upside down.