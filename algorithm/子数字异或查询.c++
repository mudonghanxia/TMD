/*
有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。
并返回一个包含给定查询 queries 所有结果的数组。

输入：arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
输出：[2,7,14,8] 
解释：
数组中元素的二进制表示形式是：
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
查询的 XOR 值为：
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
示例 2：

输入：arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
输出：[8,0,4,4]
*/
#include <vector>
using namespace std;
//动态规划--超时
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<vector<int>>ans(arr.size(),vector<int>(arr.size()));
        for(int a = 0; a < size; ++a){
            ans[a][a] = arr[a];
            for(int b = a + 1; b < size; ++b){
                ans[a][b] = ans[a][b-1]^arr[b];
            }
        }
        vector<int>ret;
        for(const auto& x:queries){
            ret.push_back({ans[x[0]][x[1]]});
        }
        return ret;
    }
};

//前缀和
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> ans(size);
        ans[0] = arr[0];
        for(int a = 1; a < size; ++a){
            ans[a] = ans[a-1]^arr[a];
        }
        vector<int>ret;
        for(const auto& x:queries){
            if(x[0] == 0) ret.push_back(ans[x[1]]);
            else ret.push_back(ans[x[0]-1]^ans[x[1]]);
        }
        return ret;
    }
};
