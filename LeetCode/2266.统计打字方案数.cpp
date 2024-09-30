/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */

// @lc code=start
class Solution {
public:
    int countTexts(string pressedKeys) {
        long long mod = 1000000007;
        int n = pressedKeys.size();
        unordered_map<int, int> ht = {{'2', 3}, {'3', 3}, {'4', 3}, {'5', 3}, {'6', 3}, {'7', 4}, {'8', 3}, {'9', 4}};
        long long sum = 1;

        int start = 0, end = 0;
        while(start < n){
            char sign = pressedKeys[start];
            while(pressedKeys[end] == sign){
                end++;
            }
            int len = end - start; // 统计这一个小模块的长度
            int range = ht[sign]; // 统计这个字母可能的变化程度
            // 针对一个一个不同的小模块进行计算，如222,333,444,55这样，单独计算，最后全部乘起来就可以
            vector<int> dp(len + 1); // 每次循环创建一个新的dp数组，局部使用
            dp[0] = 1; // 初始化
            //cout << start << end << sign << range << len << endl;
            
            for(int i = 0; i < len + 1; ++i){
                for(int j = 1; j <= range; ++j){ // 这里j要初始化为1的，代表字母的长度最短是1，不能是0
                    if(i - j >= 0){
                        dp[i] = (dp[i] + dp[i - j]) % mod;
                    }
                }
            }
            // for(auto num : dp){
            //     cout << num << ' ';
            // }
            // cout << endl;
            start = end;
            sum = sum * dp[len] % mod;
        }
        return sum;
    }
};
// @lc code=end

