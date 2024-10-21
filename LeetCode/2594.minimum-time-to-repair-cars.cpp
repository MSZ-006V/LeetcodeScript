/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        // 二分查找求最小类型问题
        long long left = 0, right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(left <= right){
            long long mid = left + (right - left) / 2; // 目前修车时间
            long long cnt = 0;
            for(auto rank : ranks){
                cnt += sqrt(mid / rank);
            }
            if(cnt >= cars){ // 修好车的数量大于目标数量，说明时间多了，可以减少一点
                right = mid - 1;
            }
            else{
                left = mid + 1; // 修车时间太少了，不能修完全部目标数量的车
            }
        }
        return left;
    }
};
// @lc code=end

