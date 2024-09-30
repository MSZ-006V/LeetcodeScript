class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0
        int left = 0, right = nums.size() - 1;
        long leftNum = nums[0], rightNum = nums[right];
        // 实际上是贪心策略，因为计算了右边和左边的值，比如最开头是4，最末尾是1，那么右边小了，就要想办法让右边的值和4一样，达到回文序列的要求
        while(left < right){
            if(leftNum < rightNum){ // 左边小了，先让左边的两个值加起来用和替代试试
                left++;
                leftNum += nums[left];
                operations++;
            }
            else if(leftNum > rightNum){ // 右边小了，就让右边的试试
                right--;
                rightNum += nums[right];
                operations++;
            }
            else { // 当左右两边相等的时候，说明这时候的left和right是相等的，已经是回文序列了
            // 因此全部增，然后更新值，重新开始计算，这一步不用计算operations
                left++;
                right++;
                leftNum += nums[left];
                rightNum += nums[right];
            }
        }
        // 最后一定能得到一个回文数组，因为长度为1的数组是回文数组
        return operations;

    }
};