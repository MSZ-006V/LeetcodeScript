class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // tc O(n), sc O(1), optimal
        // 主要利用一个性质，数组中的一共有n个数，所有数的范围都在[1, n]之间
        // 所以int idx = abs(num) - 1绝对不会出现数组越界
        // 当访问到负数的时候，就代表这个位置之前已经被访问过了，说明当前的这个num
        // 在之前也出现过，就是重复的数字
        for(int num : nums){
            int idx = abs(num) - 1;
            if(nums[idx] < 0) return abs(num);
            nums[idx] *= -1;
        }
        return -1;
    }
};
