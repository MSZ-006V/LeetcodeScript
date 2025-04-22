/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        queue<vector<int>> que;
        que.push({});
        int idx = 0;

        while(!que.empty() && idx < n){
            int size = que.size();

            for(int i = 0; i < size; ++i){
                vector<int> cur = que.front(); que.pop();
                que.push(cur);

                cur.push_back(nums[idx]);
                que.push(cur);
            }
            idx++;
        }

        vector<vector<int>> results;
        while(!que.empty()){
            results.push_back(que.front());
            que.pop();
        }

        return results;
    }
};
// @lc code=end

