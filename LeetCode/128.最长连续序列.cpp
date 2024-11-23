/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 下面这个写法实际运行时间更短，但是时间复杂度是O(nlogn)
        // if(nums.size() == 0)
        //     return 0;
        // sort(nums.begin(), nums.end());
        // int seq_len = 1;
        // int ans = 1;
        // for(int i = 1; i < nums.size(); ++i){
        //     if(nums[i] == nums[i - 1]) continue; // 遇到相同的就跳过，比如0,1,1,2，会跳过第二个1
        //     if(nums[i] - nums[i - 1] == 1){
        //         seq_len++;
        //     }
        //     else{
        //         ans = max(ans, seq_len);  // 遇到不连续的了，记录最大的，然后重新算开头
        //         seq_len = 1;
                
        //     }
        // }
        // ans = max(ans, seq_len);
        // return ans;

        // 在lc上下面这个解法耗时更多，但是时间复杂度满足题意，是O(n)
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

