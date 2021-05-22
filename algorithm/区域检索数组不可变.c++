/*
给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
实现 NumArray 类：

NumArray(int[] nums) 使用数组 nums 初始化对象
int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）

输入：
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
输出：
[null, 1, -1, -3]

解释：
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//暴力法，一开始只能想到暴力法，勉强能过
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        array = new int[size];
        for(int a = 0; a < size; a++) array[a] = nums[a];
    }
    int sumRange(int i, int j) {
        int ans = 0;
        for(int a = i; a <= j; a++) ans += array[a];
        return ans;
    }
    int* array;
};

//第二种办法；
//使用动态规划，存储所有可能

//更高效的办法
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        if(size > 0){
            array = new int [size];
            array[0] = nums[0];
            for(int a = 1; a < size; a++) array[a] = array[a-1] + nums[a];
        }
    }
    int sumRange(int i, int j) {
        return (i > 0) ? array[j] - array[i-1] : array[j];
    }
    int* array;
};
