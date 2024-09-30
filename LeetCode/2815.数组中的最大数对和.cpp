/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 *
 * [2815] 数组中的最大数对和
 */

// @lc code=start
class Solution {
public:
    int get_max(int n){
        int max_val = 0;
        while(n > 0){
            max_val = max(max_val, n % 10);
            n = n / 10;
        }
        return max_val;
    }
    int maxSum(vector<int>& nums) {
        int maxSum = 0;
        vector<int> max_val = vector<int>(10, 0);

        for(auto num : nums){
            int high = get_max(num);
            cout << high << endl;
            if(max_val[high] != 0){
                maxSum = max(maxSum, num + max_val[high]);
            }
            max_val[high] = max(max_val[high], num);
        }

        if(maxSum == 0){
            return -1;
        }
        return maxSum;
    }
};
// @lc code=end

