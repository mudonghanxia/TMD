/*
给你一个字符串 s，找到 s 中最长的回文子串。

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

输入：s = "cbbd"
输出："bb"

输入：s = "a"
输出："a"

输入：s = "ac"
输出："a"
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
//动态规划
//从i到j是否是回文字符串，是与i+1与j-1是否是回文有关。若是i+1与j-1是回文，且s[i]==s[j]。所以ans[i][j]是回文
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 0) return "";
        string ret;
        ret += s[0];
        for(int a = 1; a < size; a++){
            if(s[a] == s[0]){
                int x = 0,y = a;
                while(x < y){
                    if(s[x] != s[y]) break;
                    x++;
                    y--; 
                }
                if(x >= y) ret = s.substr(0,a + 1);
            }
        }
        vector<vector<bool>> ans(size,vector<bool>(size));
        for(int a = 0; a < size; a++){
            ans[0][a] = (s[a] == s[0]);
            ans[a][a] = true;
        }
        for(int a = 1; a < size; a++){
            for(int b = 1; b < a; b++){
                ans[b][a] = (s[a] == s[b]) && ((b+1 <= a-1) ? ans[b+1][a-1] : true);
                if(ans[b][a] && (a-b + 1 > ret.size())) ret = s.substr(b,a-b + 1);
            }
        }
        return ret;
    }
};

//第二种算法
//根据1的改进
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto pair_1 = expandAroundCenter(s, i, i);
            auto pair_2 = expandAroundCenter(s, i, i + 1);
            if (pair_1.second - pair_1.first > end - start) {
                start = pair_1.first;
                end = pair_1.second;
            }
            if (pair_2.second - pair_2.first > end - start) {
                start = pair_2.first;
                end = pair_1.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
