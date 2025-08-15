class Solution {
public:
    int findMin(vector<int> &nums) {
        // tc O(logn), sc O(1)
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = nums[0];
        while(left <= right){
            int mid = left + (right - left) / 2;
            res = min(res, nums[mid]);
            if(nums[mid] <= nums[right]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return res;
    }
};
