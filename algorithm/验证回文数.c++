/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
输入: "A man, a plan, a canal: Panama"
输出: true
输入: "race a car"
输出: false
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//我的做法:
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        if(size == 0) return true;
        deque<char>ans;
        for(int a = 0; a < size; a++){
            if( (s[a] >= 'a' && s[a] <= 'z')||
                (s[a] >= '0' && s[a] <= '9'))
                ans.push_back(s[a]);
            if((s[a] >= 'A' && s[a] <= 'Z'))
                ans.push_back(s[a] + 32);
        }
        while(!ans.empty()){
            if(ans.front() != ans.back()) return false;
            ans.pop_front();
            if(ans.empty()) return true;
            ans.pop_back();
        }
        return true;
    }
};

//筛选加判断
//申请一个新string,选择性的加入,若是不符合要求的删除即可,使用reverse函数反转后,进行判断相等
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};

//双指针
//方法同上,不使用severse函数反转,使用双指针判断
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

//直接在原string上进行双指针
//<stdlib.h>中isalnum函数可以进行判断所给字符串是否为数字和字母,若不是返回false
//<ctype.h>中的tolower函数可以将给定的字符转换为小写字符,若存在小写字符,则返回小写字符,否则返回原字符
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
