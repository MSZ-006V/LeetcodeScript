/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 *
 * [2438] 二的幂数组中查询范围内的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        // 相加为n的2的幂就是n二进制表达式的每一位相加
        while(n > 0){
            int lb = n & -n; // 取出n的最后一位一所在的位置
            powers.push_back(lb);
            n = n ^ lb; // 取出后，把n的最后一位1变为0
        }
        vector<int> result;
        for(auto query : queries){
            int x = query[0], y = query[1];
            int product = accumulate(powers.begin() + x, powers.begin() + y + 1, 1, [](int x, int y){
                return (long long) x * y % 1000000007; // 主要是防止溢出
                // x是上一次计算的结果，y是这一次的结果，先把x转为longlong防止溢出
            });
            result.push_back(product);
        }
        return result;
    }
};
// @lc code=end

