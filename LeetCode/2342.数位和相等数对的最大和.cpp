/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution {
public:
    int Count(int n){
        int sum = 0;
        while(n > 0){
            sum = sum + (n % 10);
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> ht;
        int max_sum = 0;
        for(auto num : nums){
            int cnt = Count(num);
            if(ht.find(cnt) != ht.end()){
                max_sum = max(max_sum, num + ht[cnt]);
            }
            ht[cnt] = max(ht[cnt], num);
        }
        if(max_sum == 0) return -1;
        return max_sum;
    }
};
// @lc code=end

