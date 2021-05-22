/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器。
*/

/*
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

输入：height = [1,1]
输出：1

输入：height = [4,3,2,1,4]
输出：16

输入：height = [1,2,1]
输出：2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//解法：
//算法思想：使用双指针，由于数据最终取决于下标直接的距离和下标对于数据中的最小值，所以不断移动数据最小值，并保存当前最大结果即可
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0;
        int end = height.size() - 1;
        if(end == -1) return 0;
        int ans = 0;
        int choice;
        while(begin < end){
            choice = min(height[begin],height[end]) * (end - begin);
            if(choice > ans) ans = choice;
            if(height[begin] > height[end]) end--;
            else begin++;
        }
        return ans;
    }
};
