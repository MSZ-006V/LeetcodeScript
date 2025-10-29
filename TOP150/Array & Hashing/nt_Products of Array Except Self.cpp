class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // tc O(n), sc O(n)
        // 主要就是使用前缀和后缀数组，然后两边一乘就可以
        // nums = [1, 2, 4, 6]
        // prefix = [1, 2, 8, 48]
        // suffix = [48, 48, 24, 6]
        // 使用这个公式计算即可result[i] = prefix[i - 1] * suffix[i + 1];

        int size = nums.size();

        vector<int> prefix(size);
        vector<int> suffix(size);
        vector<int> result(size);

        int sum = 1;
        for(int i = 0; i < size; ++i){
            sum *= nums[i];
            prefix[i] = sum;
        }

        sum = 1;
        for(int i = size - 1; i > -1; --i){
            sum *= nums[i];
            suffix[i] = sum;
        }

        // 特殊处理开头和结尾
        result[0] = suffix[1];
        result[size - 1] = prefix[size - 2];

        for(int i = 1; i <= size - 2; ++i){
            result[i] = prefix[i - 1] * suffix[i + 1];
        }
        return result;
    }
};
