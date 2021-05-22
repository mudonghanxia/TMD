/*
给定一个整数 n，返回 n! 结果尾数中零的数量。

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//死板解法即为我的解法
class Solution {
public:
    int trailingZeroes(int n){
        int number = 0;
        long long ans = 1;
        for(int a = 2; a <= n; a++){
            while(ans % 10 == 0){
                ans /= 10;
                number++;
            }
            ans *= a;
            ans %= 10000000;
        }
        while(ans % 10 == 0){
            ans /= 10;
            number++;
        }
        return number;
    }
};

//官方解法：
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) res += n / 5, n /= 5;
        return res;
    }
};
//本质上我的死板解法是去求了阶乘，但是由于求阶乘计算量以及数据溢出，我选择了去除结尾的0后，进行计算。
//但是实际上，结尾的0，按照因式分解来得，数据只与5有关，10是由5×2来的，那么2，随便一个偶数就可以提供好几个2，5需要隔五个来一个，所以，数据本质上多少个2×5对，由于2的个数远大于5，所以计算转换为出现多少个5。
