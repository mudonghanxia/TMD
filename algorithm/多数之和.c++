/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

输入：[3,2,3]
输出：3

输入：[2,2,1,1,1,2,2]
输出：2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//我的做法：
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int number = nums[0];
        int number_size = 1;
        int sszie = size / 2;
        for(int a = 1; a < size; a++){
            if(number != nums[a]){
               number_size = 0;
               number = nums[a];
            }
            number_size++;
            if(number_size > sszie) return nums[a];
        }
        return number;
    }
};

//官方的先排序做法：
//由于n/2，所以最中间的数一定在其中
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
//哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};

//随机化
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        while (true) {
            int candidate = nums[rand() % nums.size()];
            int count = 0;
            for (int num : nums)
                if (num == candidate)
                    ++count;
            if (count > nums.size() / 2)
                return candidate;
        }
        return -1;
    }
};
