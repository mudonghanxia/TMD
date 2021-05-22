/*
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须 原地 修改，只允许使用额外常数空间。 
输入：nums = [1,2,3]
输出：[1,3,2]

输入：nums = [3,2,1]
输出：[1,2,3]

输入：nums = [1,1,5]
输出：[1,5,1]

输入：nums = [1]
输出：[1]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

//算法思想在于，排列只有在该排列倒数仍是降序的时候，不存在下一个排序。重点是降序。
//当我们找到第一个不是升序的组合【i，i+1】组合停止。再次从倒数开始往前找第一个比i+1大的元素。
//swap以后，进行reverse，后变成升序。即为结果
