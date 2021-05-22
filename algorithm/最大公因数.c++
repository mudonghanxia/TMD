#include <iostream>
#include <algorithm>
using namespace std;

/*
最大公因数，也称最大公约数、最大公因子，指两个或多个整数共有约数中最大的一个。
a，b的最大公约数记为（a，b），同样的，a，b，c的最大公约数记为（a，b，c），
多个整数的最大公约数也有同样的记号。求最大公约数有多种方法，常见的有质因数分解法、
短除法、辗转相除法、更相减损法。与最大公约数相对应的概念是最小公倍数，a，b的最小公倍数记为[a，b]。
*/
int main(){
    //__gcd(int bigger,int smaller);
    cout << __gcd(100,10);
    return 0;
}
