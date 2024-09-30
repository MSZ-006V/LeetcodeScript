/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> diff;
        diff.push_back(0);
        int pre = 0;
        for(int i = 0; i < hours.size(); ++i){
            int num = 0;
            if(hours[i] - 8 > 0){
                num = 1;
            }
            else{
                num = -1;
            }
            pre += num;
            diff.push_back(pre);
        }
        // 时间有点慢，容易超时
        int max_len = 0;
        int max_val = 0;
        for(int i = 1; i < diff.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(diff[i] - diff[j] > 0){
                    max_len = max(max_len, i - j);
                    max_val = max(max_val, diff[i] - diff[j]);
                }
            }
        }
        return max_len;
    }
};
// @lc code=end

