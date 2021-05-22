// 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length。
// 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
// 输入：numbers = [2,7,11,15], target = 9
// 输出：[1,2]
// 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
// 输入：numbers = [2,3,4], target = 6
// 输出：[1,3]
// 输入：numbers = [-1,0], target = -1
// 输出：[1,2]
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
//二分法：（自写）
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int FF;
        int size = numbers.size() - 1;
        for(int a = 0; a <= size; a++){
            FF = find(numbers,a + 1,size,target - numbers[a]);
            if(FF == INT_MAX) continue;
            ans.push_back(a + 1);
            ans.push_back(FF + 1);
            return ans;
        }
        return ans;
    }
    int find(const vector<int>& number,int begin,int end,const int& value){
        if(end >= begin){
            int mid = begin + (end - begin)/2;
            if(value == number[mid]) return mid;
            if(value > number[mid]) return find(number,mid + 1,end,value);
            else return find(number,begin,mid - 1,value);
        }
        return INT_MAX;
    }
};

//二分法（官方）
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};

//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};
