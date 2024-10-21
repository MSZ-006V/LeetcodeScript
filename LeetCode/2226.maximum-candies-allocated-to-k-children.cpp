/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
class Solution {
public:
    bool judge(vector<int>& candies, int num, long long k){
        for(auto candy : candies){
            int r = candy / num;
            k -= r;
        }
        if(k <= 0){
            return true;  // 每个人分的糖果数量还可以增加
        }
        else{
            return false; // 每个人分的数量太多，有人没分到，要减少每个人分糖果数量
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(auto num : candies) sum += num;
        if(sum < k) return 0;

        long long left = 1, right = *max_element(candies.begin(), candies.end());

        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(judge(candies, mid, k) == true){ // 如果为true，说明此时分糖果数量是可以的，可以继续增加分糖果数量
                left = mid + 1;
            }
            
            else{ // 如果为false，此时分的糖果太多了，每个人不够分的，要减少分糖果数量
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end

