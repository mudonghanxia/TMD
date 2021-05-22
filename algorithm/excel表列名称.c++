/*
给定一个正整数，返回它在 Excel 表中相对应的列名称。
例如，
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

输入: 1
输出: "A"

输入: 28
输出: "AB"

输入: 701
输出: "ZY"
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
class Solution {
public:
  string convertToTitle(int n) {
		char alpha[26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		string ans;
		while (n > 0)
		{
			n -= 1;
			ans += alpha[n % 26];
			n = n / 26;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
