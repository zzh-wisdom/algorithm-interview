# TODO

1. C++常用的数学库函数
2. 排序算法总结
3. 图
4. dp <https://maomaoalgo.gitbook.io/python/hui-su-yu-dong-tai-gui-hua/bei-bao-dp>

链表的归并排序：<https://leetcode-cn.com/problems/sort-list/solution/pai-xu-lian-biao-by-leetcode-solution/>

对链表自顶向下归并排序的过程如下。

1. 找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 22 步，慢指针每次移动 11 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
2. 对两个子链表分别排序。
3. 将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。

上述过程可以通过递归实现。递归的终止条件是链表的节点个数小于或等于 11，即当链表为空或者链表只包含 11 个节点时，不需要对链表进行拆分和排序。

## 快排

<https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/>

## 有关子数组的题目：

### 求和为指定值的子数组

使用前缀和+哈希表

<https://leetcode-cn.com/problems/subarray-sum-equals-k/>

### 双指针

<https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/>

## 柱状图矩阵算法

<https://leetcode-cn.com/problems/largest-rectangle-in-histogram/>

<https://leetcode-cn.com/problems/maximal-rectangle/>
