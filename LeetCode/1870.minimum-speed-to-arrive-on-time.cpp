/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // 未通过，因为涉及到浮点数的精度问题，暂未解决，思路正确
        int length = dist.size();
        int h100 = round(hour) * 100;
        if(dist.size() - 1 >= hour) return -1;
        int left = 1, right = dist[length - 1] / ((hour - (length - 1)) * 100) + 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            double time = 0;
            for(int i = 0; i < length - 1; ++i){
                time += (dist[i] - 1) / mid + 1;
            }
            time += dist[length - 1] / mid;

            if(time > hour){ // 这时候的耗时太多了，速度慢，需要加大
                left = mid + 1;
            }
            else{ // 对应的就是耗时太短了，速度太快，需要减小
                right = mid - 1; 
            }
        }

        return left;
    }
};
// @lc code=end

