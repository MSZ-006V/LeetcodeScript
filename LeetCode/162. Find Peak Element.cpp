class Solution {
public:
    // 这道题可以认为nums[-1] == nums[n + 1] = 负无穷
    // 如果 nums[mid] > nums[mid + 1]：说明 mid 处在“下坡路”或者它本身就是峰值。那么在 mid 的左侧（包括 mid 自己）一定存在至少一个峰值。
    // 如果 nums[mid] < nums[mid + 1]：说明 mid 处在“上坡路”。那么在 mid 的右侧（不包括 mid）一定存在至少一个峰值。
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};