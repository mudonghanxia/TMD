/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
输入: [2,2,1]
输出: 1
输入: [4,1,2,1,2]
输出: 4
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//方法1,暴力法,双重循环

//方法2,使用集合，
//集合不允许不允许出现两个值相同的数据，且实现是用红黑树进行实现，自带排序
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        set<int> ans;
        for(int a = 0; a < size; a++)
            if(ans.count(nums[a])) ans.erase(nums[a]);
            else ans.insert(nums[a]);
        return *ans.begin();
    }
};

//任何数和0做异或运算，结果仍然是原来的数，即 a⊕0=a⊕0=a。
//任何数和其自身做异或运算，结果是 0，即 a⊕a=0a⊕a=0。
//异或运算满足交换律和结合律，即 a⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=ba⊕b⊕a=b⊕a⊕a=b⊕(a⊕a)=b⊕0=b。

//位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};
