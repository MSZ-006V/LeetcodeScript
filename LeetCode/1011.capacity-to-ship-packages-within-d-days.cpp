/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 这道题是二分查找的进阶应用：找最小
        // 核心原理是货船运输的货物重量是一个区间，最后目标的运输重量一定在这个区间里
        // 即左边界是最大货物重量，右边界是货物总重量、

        // 整体思路就是在这个左右区间里，不停的查找货船的运输重量，直到找到最后符合条件的最小的
        // 每一个mid都是一个新的货运重量，然后判断在这个重量下最多运输几天，是否合法，然后以此
        // 来调节左右边界
        int right = accumulate(weights.begin(), weights.end(), 0);
        int left = *max_element(weights.begin(), weights.end());
        while(left < right){
            int mid = left + (right - left) / 2; // 求出一个mid值
            int need_day = 1, cur = 0; // 需要的运输最大天数和目前运输重量
            for(auto weight : weights){
                if(cur + weight > mid){ // 如果重量超了，当前货物就要安排到下一天了
                    need_day++; // 即need_day++
                    cur = 0; // 然后把目前重量清零，然后下面重新把当前货物加上
                }
                cur += weight;
            }

            if(need_day <= days){ // 说明在当前mid运输重量下，还有冗余，天数还可以增加，货运重量可以减小
                right = mid;
            }
            else{
                left = mid + 1; // 说明当前mid重量下，消耗天数太多，要增加货运重量了！
            }
        }
        // 最后left和right是相等的
        // cout << left << ' ' << right << endl;
        return right;
        // return left; 也可以通过
    }
};
// @lc code=end

