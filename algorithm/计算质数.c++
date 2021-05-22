/*
统计所有小于非负整数 n 的质数的数量。
输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

输入：n = 0
输出：0

输入：n = 1
输出：0
*/
// 第一种算法，枚举，暴力算法，可以寻找【2，根号i】处优化
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//第二种，官方：
//埃氏筛
/*
	这个算法充分考虑到了质数与质数之间的关系，在当你找到一个质数i的时候，2×i，3×i，4×i，5×i等等就都不是质数了，我们把之前所算到的数全部充分的使用上，那么算法就会很快了。
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
