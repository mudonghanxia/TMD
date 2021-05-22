/*
种花问题
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。

输入：flowerbed = [1,0,0,0,1], n = 1
输出：true

输入：flowerbed = [1,0,0,0,1], n = 2
输出：false
*/

#include <vector>
using std::vector;

//暴力回溯
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n,int begin = 0) {
        if(n == 0) return true;
        if(begin == 0 && flowerbed[begin] == 0 && ((begin + 1 < flowerbed.size() && flowerbed[begin+1] == 0) || (begin + 1 == flowerbed.size()))){
            flowerbed[begin] = 1;
            if(canPlaceFlowers(flowerbed,n-1,begin + 1)) return true;
            flowerbed[begin] = 0;
        }
        for(;begin < flowerbed.size();++begin){
            if(flowerbed[begin] == 1) continue;
            if(begin + 1 < flowerbed.size() && flowerbed[begin + 1] == 0 &&
                ((begin+2 < flowerbed.size() && flowerbed[begin + 2] == 0) ||
                (begin + 2 == (flowerbed.size())))){
                    flowerbed[begin + 1] = 1;
                    if(canPlaceFlowers(flowerbed,n-1,begin + 1)) return true;
                }
        }
        return false;
    }
};

//巧解方法
//巧妙在前后均加0，导致只需判断是否有连续的三个0即可
class Solution {
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = 0,count = 1;  //假设在数组左边添加0，以解决边界问题，令count初始为1
        for (int i=0;i<flowerbed.size();i++){
            if (flowerbed[i] == 0){
                count++;
            }else{
                count = 0;
            }
            if (count == 3){    //每连续三个0种一次花
                num++;
                count = 1;
            }
        }
        if (count == 2){    //如果最后count为2而不是1，表示最后一个位置可以种花
            num++;
        }
        return n <= num;
    }
};

/*

class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        tmp = [0]+flowerbed+[0]
        for i in range(1, len(tmp)-1):
            if tmp[i-1] == 0 and tmp[i] == 0 and tmp[i+1] == 0:
                tmp[i] = 1  # 在 i 处栽上花
                n -= 1   
       return n <= 0   # n 小于等于 0 ，表示可以栽完花
*/
