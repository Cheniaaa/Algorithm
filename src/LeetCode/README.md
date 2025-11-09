# LeetCode

## 算法题
<details>
<summary><b>数组</b></summary>

1. [T189](./Array/T189.cpp)
2. [T977](./Array/T977.cpp)
```cpp
//使用transform数组原地操作
transform(nums.begin(), nums.end(), nums.begin(), [](int num) { return num *= num; });
//使用transform在另一个数组操作
transform(nums.begin(), nums.end(), res.begin(), [](int num) { return num *= num; });
//使用for_each数组原地操作
for_each(nums.begin(), nums.end(), [](int &num) { num *= num; });
//需要捕获res和index以完成函数操作
for_each(nums.begin(), nums.end(), [&res, &index](int num) { res[index--] = num * num; });
```

3. [T274](./Array/T274.cpp)
</details>
