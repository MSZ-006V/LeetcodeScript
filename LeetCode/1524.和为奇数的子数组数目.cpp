/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 *
 * [1524] 和为奇数的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // 具体思路还是前缀和+哈希表，前面所有的类型的子数组的和的奇偶性，全部都存储在
        // odd和even这两个变量里面了，所以不需要用一个很复杂的哈希表，用2个变量来存储就可以了
        int mod = 1000000007;
        int ret = 0;
        int even = 1;
        int odd = 0;
        int sum = 0;
        for(auto num : arr){
            sum += num;
            if(sum % 2 == 0){
                ret = (ret + odd) % mod;
                even++;
            }
            else{
                ret = (ret + even) % mod;
                odd++;
            }
        }
        
        return ret;
    }
};
// @lc code=end

