/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int max_lenght = 1;
        // 将所有元素都放入一个set，方便进行查询
        unordered_set<int> numset(nums.begin(), nums.end());
        for(int num:nums){
            if(numset.count(num - 1) == 0){ // 保证num这个元素师一个连续序列的开头，即前一个元素不存在
                int seqlen = 1;
                while(numset.count(++num) == 1){ // 向后查询，如果有就增加长度
                    seqlen++;
                }
                max_lenght = max(max_lenght, seqlen);
            }
        }
        return max_lenght;
    }
};
// @lc code=end

