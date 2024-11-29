/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    // 这题最后退化为找一个数n的所有质因数，比如4，质因数是2，比如9，质因数是3
    // 可以看官方题解，递推公式 f[i] = f[i / j] + j (i % j == 0)
    // 就遍历n的因数，然后找到一个数可以整除，然后不断地减小n，直到1或者是2或者3之类的，一直到无法分解
    int minSteps(int n) {
        int ans = 0;
        for(int i = 2; i * i <= n; ++i){
            while(n % i == 0){
                n = n / i;
                ans += i;
            }
        }

        // 所以这个if就是针对最后n是1,2,3这些情况的，因为1,2,3这些只能通过复制单个A然后粘贴得到
        // 所以直接把数量加上就可以了
        if(n > 1) ans += n;
        return ans;
    }
};
// @lc code=end

