/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    static int count(int n){
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; ++i){
            int val = count(i);
            result.push_back(val);
        }
        return result;
    }
};
// @lc code=end

