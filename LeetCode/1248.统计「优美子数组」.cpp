/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
    bool isOdd(int num){
        return num%2 == 1?true:false;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 先将数组内所有的奇数和偶数进行转换，奇数变为1，偶数变为0
        vector<int> array(nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i){
            if(isOdd(nums[i])){
                array[i] = 1;
            }
        }

        // 使用前缀和进行统计计算，思路完全一样
        int ans = 0, sum = 0;
        unordered_map<int, int> ht;
        ht[0] = 1; // 注意要讲ht[0] = 1添加进去，表示和为0的情况有1种
        for(int i = 0; i < nums.size(); ++i){
            sum += array[i];
            if(ht.find(sum - k) != ht.end()){
                ans += ht[sum - k];
            }
            ht[sum]++; // 在哈希表中记录新的
        }
        // for(auto item:ht){
        //     cout << item.first << ' ' << item.second << endl;
        // }
        return ans;
    }
};
// @lc code=end

