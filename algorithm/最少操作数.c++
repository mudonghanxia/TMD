/*
给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。

交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。

返回使 s 变成 交替字符串 所需的 最少 操作数。

输入：s = "0100"
输出：1
解释：如果将最后一个字符变为 '1' ，s 就变成 "0101" ，即符合交替字符串定义。

输入：s = "10"
输出：0
解释：s 已经是交替字符串。

输入：s = "1111"
输出：2
解释：需要 2 步操作得到 "0101" 或 "1010" 。
*/

//运行100%，内存15%。
#include <string>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        string x = s;
        int number = 0;
        for(int e = s.size()-2; e >= 0; --e){
            if(s[e] == s[e+1]){
                s[e] = (s[e+1] == '0')?'1':'0';
                ++number;
            }
        }
        if(x[s.size()-1] == '0') x[s.size()-1] = '1';
        else x[s.size()-1] = '0';
        int num = 1;
        for(int e = s.size()-2; e >= 0; --e){
            if(x[e] == x[e+1]){
                x[e] = (x[e+1] == '0')?'1':'0';
                ++num;
            }
        }
        return min(num,number);
    }
};

//思路
class Solution {
public:
    int minOperations(string s) {
        int len = s.size();
        int count = 0;
        for(int i = 0;i < len;i++)
            if((s[i] & 1) == (i & 1))
                count++;
        return min(count,len - count);
    }
};
