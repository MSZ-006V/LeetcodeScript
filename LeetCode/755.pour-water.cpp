/*
 * @lc app=leetcode id=755 lang=cpp
 *
 * [755] Pour Water
 */

// @lc code=start
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
    	int n = heights.size();
    	while(volume){
    		int left = k;
    		while(left >= 1 && heights[left-1] <= heights[left]) left--;
    		while(left < k && heights[left] == heights[left + 1]) left++;

    		if(left != k){
    			heights[left]++;
    			volume--;
    			continue;
    		}

    		int right = k;
    		while(right <= n-2 && heights[right] >= heights[right + 1]) right++;
    		while(right > k && heights[right - 1] == heights[right]) right--;

    		heights[right]++;
    		volume--;
    	}

    	return heights;
    }
};
// @lc code=end

