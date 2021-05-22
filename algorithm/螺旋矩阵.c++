/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//第一种算法，模拟
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m == 0) return ret;
        int n = matrix[0].size();
        if(n == 0) return ret;
        vector<vector<bool>> find(m+2,vector<bool>(n+2,false));
        for(int a = 0; a <= n + 1; ++a){
            find[0][a] = true;
            find[m + 1][a] = true;
        }
        for(int a = 0; a <= m + 1; ++a){
            find[a][0] = true;;
            find[a][n + 1] = true;
        }
        m = (m % 2 == 0) ? (m / 2): (m / 2 + 1);
        int m_,n_;
        for(int a = 1; a <= m; ++a){
            m_ = a;
            n_ = a;
            while(!find[m_][n_]){
                ret.push_back(matrix[m_ - 1][n_ - 1]);
                find[m_][n_] = true;
                ++n_;
            }
            --n_;
            ++m_;
            while(!find[m_][n_]){
                ret.push_back(matrix[m_ - 1][n_ - 1]);
                find[m_][n_] = true;
                ++m_;
            }
            --m_;
            --n_;
            while(!find[m_][n_]){
                ret.push_back(matrix[m_ - 1][n_ - 1]);
                find[m_][n_] = true;
                --n_;
            }
            ++n_;
            --m_;
            while(!find[m_][n_]){
                ret.push_back(matrix[m_ - 1][n_ - 1]);
                find[m_][n_] = true;
                --m_;
            }
        }
        return ret;
    }
};


//第二种算法（官方第二种）
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
