/**
 * 接雨水
 * https://leetcode.cn/problems/trapping-rain-water/
 */
#include <vector>
#include <stack>
#include "iostream"

using namespace std;


/**
 * 双指针法
 *
 * 每次需要循环寻找左右柱子
 * @param height
 * @return
 */
int trap_doublePtr(vector<int> &height) {
    int sum = 0;
    int h;//记录一列可以积累的雨水高度
    for (int i = 0; i < height.size(); ++i) {
        //第一列和最后一列不用统计雨水
        if (i == 0 || i == height.size() - 1) continue;

        //使用lHeight和rHeight记录左右柱子最高高度
        int lHeight = height[i];
        int rHeight = height[i];

        //向右寻找最高主柱子
        for (int r = i + 1; r < height.size(); ++r) {
            if (rHeight < height[r]) rHeight = height[r];
        }
        for (int l = i - 1; l >= 0; l--) {
            if (lHeight < height[l]) lHeight = height[l];
        }
        h = min(lHeight, rHeight) - height[i];
        if (h > 0) {
            sum += h;
        }
    }
    return sum;
}


/**
 * 动态规划
 *
 * 对上述双指针进行优化，避免重复的寻找左右柱子
 * @param height
 * @return
 */
int trap_dp(vector<int> &height) {
    if (height.size() <= 2) return 0;
    //将左右最高柱子记录在容器中
    vector<int> maxLeft(height.size(), 0);
    vector<int> maxRight(height.size(), 0);

    int size = height.size();
    maxLeft[0] = height[0];
    for (int i = 1; i < size; i++) {
        //将前一个与当前比较最大
        maxLeft[i] = max(height[i], maxLeft[i - 1]);
    }

    maxRight[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        maxRight[i] = max(height[i], maxRight[i + 1]);
    }

    // 求和
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int count = min(maxLeft[i], maxRight[i]) - height[i];
        if (count > 0) sum += count;
    }
    return sum;
}


/**
 * 单调栈
 * @param height
 * @return
 */
int trap_stack(vector<int> &height) {
    if (height.size() <= 2) return 0;
    int sum = 0;
    stack<int> stack;
    stack.push(0);
    for (int i = 1; i < height.size(); ++i) {
        while (!stack.empty() && height[i] > height[stack.top()]) {
            int mid = stack.top();//下凹处
            stack.pop();
            if (!stack.empty()) {
                //栈顶为左侧柱子
                //其中已经包含对高度相同柱子的解决
                int h = min(height[i], height[stack.top()]) - height[mid];
                int w = i - stack.top() - 1;
                sum += h * w;
            }
        }
        stack.push(i);
    }
    return sum;
}

