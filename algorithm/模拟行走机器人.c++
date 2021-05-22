/*
机器人在一个无限大小的 XY 网格平面上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 commands ：

    -2 ：向左转 90 度
    -1 ：向右转 90 度
    1 <= x <= 9 ：向前移动 x 个单位长度

在网格上有一些格子被视为障碍物 obstacles 。第 i 个障碍物位于网格点  obstacles[i] = (xi, yi) 。

机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续尝试进行该路线的其余部分。

返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。（即，如果距离为 5 ，则返回 25 ）
 

注意：

    北表示 +Y 方向。
    东表示 +X 方向。
    南表示 -Y 方向。
    西表示 -X 方向。

*/
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

//无脑暴力
class Solution {
    char arra[4] = {'u','r','d','l'};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0,y = 0;
        int find = 0;
        int ans = 0;
        for(auto m : commands){
            if(m > 0){
                f(x,y,arra[find],m,obstacles);
                ans = max(ans,x*x+y*y);
            }
            else if(m == -1) find = (find + 1) % 4;
            else find = (find - 1 + 4) % 4;
        }
        return ans;
    }
    void f(int& x,int& y,const char& s,const int& size,const vector<vector<int>>& obstacles){
        switch(s){
            case 'u':{
                for(int a = 1; a <= size; ++a)
                    if (!fin(x,y+1,obstacles)) ++y;
                    else break;
                break;
            }
            case 'd':{
                for(int a = 1; a <= size; ++a)
                    if (!fin(x,y-1,obstacles)) --y;
                    else break;
                break;
            }
            case 'l':{
                for(int a = 1; a <= size; ++a)
                    if (!fin(x-1,y,obstacles)) --x;
                    else break;
                break;
            }
            case 'r':{
                for(int a = 1; a <= size; ++a)
                    if (!fin(x+1,y,obstacles)) ++x;
                    else break;
                break;
            }
        }
    }
    bool fin(const int&x,const int&y,const vector<vector<int>>& obstacles){
        for (auto b = obstacles.begin(),e = obstacles.end();b != e; ++b){
            if((*b)[0] == x && (*b)[1] == y) return true;
        }
        return false;
    }
};


//官方解法+自我修改
class Solution {
    set<pair<int,int>> ans;
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto& e : obstacles)
            ans.insert({e[0],e[1]});
        int ar[4] = {1,2,3,4}; // 北 东 南 西
        int x = 0,y = 0,sum = 0,begin = 0;
        for(auto m : commands){
            if(m > 0){
                switch(ar[begin]){
                    case 1:{
                        for(int a = 1; a <= m; ++a){
                            if(ans.count({x,y+1})) break;
                            ++y;
                        }
                        break;
                    }
                    case 2:{
                        for(int a = 1; a <= m; ++a){
                            if(ans.count({x+1,y})) break;
                            ++x;
                        }
                        break;
                    }
                    case 3:{
                        for(int a = 1; a <= m; ++a){
                            if(ans.count({x,y-1})) break;
                            --y;
                        }
                        break;
                    }
                    case 4:{
                        for(int a = 1; a <= m; ++a){
                            if(ans.count({x-1,y})) break;
                            --x;
                        }
                        break;
                    }
                }
                sum = max(sum,x*x+y*y);
            }
            else if(m == -1) begin = (begin + 1) % 4;
            else begin = (4 + begin - 1) % 4;
        }
        return sum;
    }
};

//执行用例中的优秀代码
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //亮点就在这里：使用了一个二维数组，省去我手动打三十行switch case代码
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; 
        int turn = 0;
        int x = 0, y = 0;
        int res = 0;
        set<pair<int,int>> mySet;
        for (auto& e : obstacles)
            mySet.insert({e[0], e[1]});
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2)
                turn = turn == 0 ? 3 : turn - 1;
            else if (commands[i] == -1)
                turn = (turn + 1) % 4;
            else {
                while (commands[i]--) {
                    int nextx = x + dir[turn][0];
                    int nexty = y + dir[turn][1];
                    if (!mySet.count({nextx, nexty})) {
                        x = nextx;
                        y = nexty;
                        res = max(res, nextx * nextx + nexty * nexty);
                    } else
                        break;
                }
            }
        }
        return res;
    }
};

//在使用for(auto ： )的时候，巧加&和const可以大幅度提升速率
