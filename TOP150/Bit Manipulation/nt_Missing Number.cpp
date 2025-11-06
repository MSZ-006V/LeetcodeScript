class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = n;
        for(int i = 0; i < n; ++i){
            xorr ^= i ^ nums[i];
        }
        return xorr;
        // 核心思想（使用XOR异或的性质）：
        // 1. a ^ a = 0
        // 2. a ^ 0 = a
        // 3. 交换律和结合律：a ^ b ^ a = b

        // 只会有一个缺失的数字，所以使用 i 和 nums[i] 进行异或操作后，就能知道该位置 i 对应的数字是否缺失
        // 因为异或可以交换顺序、重复的会抵消：所有在 nums 里出现的数字都会和 [0,n] 里的同一个数抵消掉，唯一没出现的那个数不会被抵消，最终就会留下来。
    }
};
