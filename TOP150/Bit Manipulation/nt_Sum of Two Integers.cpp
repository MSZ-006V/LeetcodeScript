class Solution {
public:
    int getSum(int a, int b) {
        // leetcode 371 核心思想：使用位运算实现加法
        // a ^ b 是不考虑进位的加法
        // (a & b) << 1 是计算进位
        // a = a ^ b 相当于把不考虑进位的加法结果赋值给 a
        // b = carry 是把进位赋值给 b
        while(b != 0){
            int carry = (a & b) << 1; // 计算进位
            a ^= b; // 先计算不考虑进位的加法
            b = carry; // 再把进位赋值给 b，继续下一轮计算
            // 到了下一轮，就会判断是否有进位，如果没有进位则算法结束，如果有进位就
            // 使用 (a & b) << 1，然后把进位b加到a上面
        }
        return a;
    }
};
