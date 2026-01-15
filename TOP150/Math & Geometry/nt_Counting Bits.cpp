class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; ++i){
            dp[i] = dp[i >> 1] + (i & 1);
        }
        // i & 1: 取 i 的最后一位（二进制的最低位），如果i是偶数，那么就是0，如果是奇数那么是1
        // i >> 1: 去掉数字i的最后一位，即没有加上1之前的情况
        // 基本思路就是先得到当前i - 1的1的个数，然后查看i - 1
        // i 的 1 的个数 = (i >> 1) 的 1 的个数 + i 的最低位是不是 1
        return dp;
    }
};
