// 编写一个算法来判断一个数 n 是不是快乐数。
// 「快乐数」定义为：
// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果 可以变为  1，那么这个数就是快乐数。
// 如果 n 是快乐数就返回 true ；不是，则返回 false 。

// 输入：19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// 输入：n = 2
// 输出：false
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
//@@@ 看到无限循环不要慌，循环循环，都是一个圈，既然是一个圈，最终要么是会与之前的数据重合，要么就会走到结果1。所以就有了，unordered_set
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_set<int> ans;
        ans.insert(n);
        int number = n;
        while(true){
            n = 0;
            while(number){
                n = (number % 10) * (number % 10) + n;
                number /= 10;
            }
            if(ans.count(n)) return false;
            else ans.insert(n);
            if(n == 1) return true;
            number = n;
        }
        return true;
    }
};
