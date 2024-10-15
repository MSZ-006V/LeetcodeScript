/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end()), left = 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            long long hour = 0;
            for(auto pile : piles){
                hour += (pile - 1) / mid + 1;
            }
            
            if(hour > h){ // 用时比规定时间多，吃的速度慢了，要加快
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

