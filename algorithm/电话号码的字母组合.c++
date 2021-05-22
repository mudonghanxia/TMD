/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
输入: nums = [1,2,3,1], k = 3
输出: true
输入: nums = [1,0,1,1], k = 1
输出: true
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

//暴力法，超时。
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//使用map，调用find函数，匹配键与当前元素是否匹配，若是存在该键，判断值与当前下标是否差值k,返回true，若是与当前下标相差超过k，
//修改值为当前下标，即只记忆最后一次出现的下标。若是不存在该键，则创建该键
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int size = nums.size();
        for(int a = 0; a < size; a++){
            if(map.find(nums[a]) != map.end()){
                if(a - map[nums[a]] <= k) return  true;
                else map[nums[a]] = a;
            }
            else map[nums[a]] = a;
        }
        return false;
    }
};
