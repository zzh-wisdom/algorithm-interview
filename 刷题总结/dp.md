# DP

## 环形数组的最大连续子数组之和

https://www.nowcoder.com/questionTerminal/5a2a527f68b6434ba0b4faadcdc97812?f=discussion

思路：

两次dp：

- 一次算连续最大子数组之和 A
- 另一次算连续最小子数组之和 C

答案为 max(A, sum-C)

```c++
int cur_max = 0;
int max_sum = 0;
int cur_min = 0;
int min_sum = 0;
for(int i = 0; i < N; ++i) {
    cur_max = max(A[i], cur_max + A[i]);
    max_sum = max(cur_max, max_sum);
    cur_min = min(A[i], cur_min + A[i]);
    min_sum = min(cur_min, min_sum);
}
cout << max(max_sum, sum - min_sum) << endl;
```

