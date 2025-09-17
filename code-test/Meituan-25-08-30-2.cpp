#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

void count(long long n, long long k){
    while(k > 0){
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n = (n * 3) + 1;
        }
        k--;
    }   
    cout << n << endl;
}
int main() {
    long long n, k;
    while (cin >> n >> k) { // 注意 while 处理多个 case
        count(n, k);
    }
}
// 64 位输出请用 printf("%lld")