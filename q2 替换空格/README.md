# Q2 替换空格

## 解题总结

1. 需要注意传入数组为空的情况
2. 从后往前添加可以减少内存的消耗



## JAVA

StringBuffer的选择：

1. 和 String 类不同的是，StringBuffer 和 StringBuilder 类的对象能够被多次的修改
2. StringBuilder不是线程安全的，但相较于StringBuilder有速度上的优势
3. String 获取长度的方法是`.length()` 而array获取长度的方法是`.length`
4. StringBuffer没有重载[]，需要用到`ChatAt()`和`setChatAt()`来更改字符。
5. StringBuffer使用`setLength()`来改变长度

