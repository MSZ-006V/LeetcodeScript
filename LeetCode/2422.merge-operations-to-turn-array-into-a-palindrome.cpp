class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        long left_v = nums[0], right_v = nums[nums.size() - 1];
        int left = 0, right = nums.size() - 1;
        while(left < right){
            if(left_v < right_v){
                left++;
                left_v += nums[left];
                op++;
            }
            else if(left_v > right_v){
                right--;
                right_v += nums[right];
                op++;
            }
            else{
                left++;
                right--;
                left_v = nums[left];
                right_v = nums[right];
            }
        }

        return op;
    }
};