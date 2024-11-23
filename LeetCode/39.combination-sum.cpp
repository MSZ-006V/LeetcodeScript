/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtracking(vector<int>& candidates, int target, vector<int>& path, int& sum, int index){
        if(sum == target){
            result.push_back(path);
        }
        for(int i = index; i < candidates.size(); ++i){ // 使用index就是去重的，不用从头访问
            if(sum + candidates[i] <= target){
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, path, sum, i);
                sum -= candidates[i];
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 找到candidates中数，相加等于target的组合，不能重复
        // 一个简单题，直接在回溯中去重就可以
        vector<int> path;
        int sum = 0;
        backtracking(candidates, target, path, sum, 0);

        return result;
    }
};
// @lc code=end

