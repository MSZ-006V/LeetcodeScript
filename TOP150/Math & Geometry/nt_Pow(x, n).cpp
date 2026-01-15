class Solution {
public:
    // tc: O(log n), sc: O(1)
    // 传统的需要计算 n 次乘法，时间复杂度是 O(n)
    // 使用快速幂算法，时间复杂度是 O(log n)，通过把n转换为二进制，从而保证时间复杂度是log n
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1) return 1;

        double res = 1;
        long power = abs((long)n);

        while(power){
            if(power & 1) {
                res *= x;
            }
            x *= x;
            power >>= 1;
        }

        return n >= 0 ? res : 1 / res;
    }
};
