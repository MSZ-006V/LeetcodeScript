class Solution {
public:
    int search(vector<int>& nums, int target) {
        // tc O(logn), sc O(1)
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            if(nums[0] <= nums[mid]){ // left ~ mid 是有序的
                if(nums[mid] > target && target >= nums[0]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[n - 1]){
                    left = mid + 1;
                }   
                else{
                    right = mid - 1;
                }
            }
        } 
        if(left >= n) return -1;
        return nums[left] == target? left : -1;
    }
};

// 更优解
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            }

            if (nums[left] <= nums[mid]) { // left ~ mid - 1有序，mid + 1 ~ right无序
                if (target > nums[mid] || target < nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // left ~ mid - 1无序，mid + 1 ~ right有序
                if (target < nums[mid] || target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};
