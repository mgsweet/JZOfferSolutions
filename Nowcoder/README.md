# 牛客网刷题

## NC22 合并两个有序数组

不需要重新开空间，因为其中一个数组有多余空间。

由于多余空间在后方，我们可以从后往前合并，这样可以利用到后方的多余空间。



## NC50

需要使用dummy指针加单个插入的方法，生成的链表连续不会断开，比较好处理

旋转链表优化方案：

```c++
class Solution {
public:
  ListNode *ReverseList(ListNode *p_head) {
    if (!p_head) return p_head;
    ListNode *dummy = new ListNode(0);
    dummy->next = p_head;
    ListNode *p_node = p_head, *p_tmp;
    while (p_node->next) {
       p_tmp = p_node->next;
       p_node->next = p_node->next->next;
       p_tmp->next = dummy->next;
       dummy->next = p_tmp;
    }
    p_head = dummy->next;
    delete dummy;
    return p_head;
  }
};
```

# ![nc50](../img/nc50.jpeg)

