/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> preSum(n); // 统计数组中盘子的个数，用作前缀和
        for(int i = 0, sum = 0; i < n; ++i){
            if(s[i] == '*'){
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n); // 统计左蜡烛的位置
        for(int i = 0, l = -1; i < n; ++i){
            if(s[i] == '|'){
                l = i;
            }
            left[i] = l;
        }

        vector<int> right(n); // 从后往前，统计区间的右边蜡烛的位置
        for(int i = n - 1, r = -1; i >= 0; --i){
            if(s[i] == '|'){
                r = i;
            }
            right[i] = r;
        }
        
        vector<int> result;
        for(auto query : queries){
            int x = right[query[0]], y = left[query[1]]; 
            // 通过这种方法，就可以分别找到要查找的区间内，最靠近的左蜡烛和右蜡烛位置
            result.push_back(x == -1 || y == -1 || x >= y?0:preSum[y] - preSum[x]);
        }
        return result;
    }
};
// @lc code=end

