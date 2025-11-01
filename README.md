# 知识点
<details>
<summary>Lambda表达式</summary>

**应用**：[T189](./src/LeetCode/Array/T189.cpp)
1. **基本语法结构**
   ```cpp
   [capture-list] (parameters) -> return-type { function-body }
   ```
2. **捕获列表详解**

| 语法        | 说明             | 示例                        |
|-----------|----------------|---------------------------|
| []        | 不捕获任何变量        | [] { return 42; }         
| [=]       | 按值捕获所有外部变量	    | [=] { return x + y; }     
| [&]       | 	按引用捕获所有外部变量	  | [&] { x++; return y; }    
| [var]     | 	按值捕获特定变量	     | [x] { return x * 2; }     
| [&var]    | 	按引用捕获特定变量	    | [&x] { x = 10; }          
| [=, &var] | 	默认按值，特定变量按引用	 | [=, &x] { return x + y; } 
| [&, var]  | 	默认按引用，特定变量按值	 | [&, x] { y = x; }         

3. **参数列表**

```cpp
// 普通参数
[](int a, int b) { return a + b; }

// auto参数（C++14）
[](auto a, auto b) {
return a + b; }

// 可变参数模板（C++14）
[](auto&&... args) {
process(args...); }

// 默认参数（C++14）
[](int a, int b = 10) {
return a + b; }
```

4. **返回类型**

```cpp
// 自动推导返回类型
[](int x) { return x * 2; } // 推导为int

// 显式指定返回类型
[](int x) -> double {
return x * 2.0; }    // 显式返回double

// 多返回路径需要显式指定
[](bool flag) -> int {
if (flag) return 1;
else return 0;  // 两个return，需要显式类型
}
```

5. **mutable关键字**

```cpp
// 无mutable：按值捕获的变量是const
[x = 0]() { return x; }; // 正确
[x = 0]() { x++; return x; }; // 错误！x是const

// 有mutable：可以修改按值捕获的变量
[x = 0]() mutable { x++; return x; }; // 正确
```

6. **特殊形式和特性**

6.1 立即调用（IIFE）

```cpp
const auto result = [](int x) {
return x * x;
}(5); // 立即调用，result = 25
```

6.2 递归lambda

```cpp
// 使用std::function
std::function<int(int)> factorial =[&](int n) -> int {
return n <= 1 ? 1 : n * factorial(n - 1);
};

// 使用auto + 显式类型（C++14）
auto factorial =[](auto self, int n) -> int {
return n <= 1 ? 1 : n * self(self, n - 1);
};
factorial(factorial, 5); // 调用方式
```

6.3 泛型lambda（C++14）

```cpp
auto add = [](auto a, auto b) { return a + b; };
add(1, 2); // int
add(1.5, 2.3); // double
```

7. **存储和使用方式**
   7.1 使用auto存储

```cpp
auto lambda =[](int x) { return x * x; };
int result = lambda(5); // 25
```

7.2 使用std::function存储

```cpp
#include<functional>
std::function<int(int)> func =[](int x) {
return x * x; };
```

7.3 作为函数参数
```cpp
// 接受lambda作为参数
void process(const std::function<void(int)>& func) {
func(42);
}

// 调用
process([](int x) {
std::cout << x; });
```
</details>