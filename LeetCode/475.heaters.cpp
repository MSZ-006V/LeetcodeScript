/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 原来的思路也没错，但是很复杂实现起来
        // 原思路是遍历半径，检查每个房子是否在加热器范围内，这一步比较困难，比较难实现，容易超时溢出

        // 目前这个思路是：每个房子一定是由离它最近的2个（或1个）加热器供暖的，只要找出
        // 每个房子附近的加热器的最短供暖半径，全部放入一个数组里面，再取这个数组的最大值
        // 就是加热器的最小供热半径，这个半径可以保证所有房子都会供热，比较简单，时间复杂度也不高
        int heaters_num = heaters.size();
        sort(heaters.begin(), heaters.end());
        vector<int> min_radius;

        for(auto house : houses){
            int h = ranges::lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int min_r = 100000000;
            if(h == 0){
                min_r = abs(house - heaters[h]);
            }
            else if(h == heaters_num){
                min_r = abs(house - heaters[h - 1]);
            }
            else{
                min_r = min(abs(house - heaters[h]), abs(house - heaters[h - 1]));
            }
            min_radius.push_back(min_r);
        }
        
        return *max_element(min_radius.begin(), min_radius.end());
    }
};
// @lc code=end

