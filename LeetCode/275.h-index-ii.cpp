/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 1, right = n;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(citations[n - mid] >= mid){
                left = mid +1;
            }
            else{
                right = mid - 1;
            }
        }
        return right; // 返回的是right，right = left - 1, right + 1 = left
        // left表示的是不满足的数量，而right表示的是满足的，所以返回的是right
    }
};
// @lc code=end

