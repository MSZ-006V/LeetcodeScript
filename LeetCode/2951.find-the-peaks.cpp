/*
 * @lc app=leetcode id=2951 lang=cpp
 *
 * [2951] Find the Peaks
 */

// @lc code=start
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        for(int i = 1; i <= mountain.size() - 2; ++i){
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]){
                res.push_back(i);
            }
        }

        return res;
    }
};
// @lc code=end

