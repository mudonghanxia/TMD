#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//质数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。
bool function(const int& a){
    int x = sqrt(a) + 1;
    for(int y = 2; y < x; ++y){
        if(a % y == 0) return false;
    }
    return true;
}
int main (){
    vector<int> ret;
    ret.push_back(2);
    vector<bool> ans(1000,true);
    ans[0] = false;
    ans[1] = false;
    for(int a = 3; a < 1000; ++a){
        if(ans[a]){
            if(function(a)) ret.push_back(a);
            for(int x = a * 2; x < 1000; x += a){
                ans[x] = false;
            }
        }
    }
    int x = 100,y = x / 2;
    cout << x << "=2";
    for(int a = 2; a <= y; ++a){
        if(ans[a] && (y % a == 0)){
            cout << "*" << a;
            y /= a;
            --a;
        }
    }
    return 0;
}
