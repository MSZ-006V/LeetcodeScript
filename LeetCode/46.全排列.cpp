/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtracking(vector<int>& nums, vector<bool>& visited, vector<int> path){
        if(path.size() == visited.size()){
            result.push_back(path);
        }

        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i]){
                path.push_back(nums[i]);
                visited[i] = true;
                backtracking(nums, visited, path);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        for(int i = 0; i < nums.size(); ++i){
            path.push_back(nums[i]);
            visited[i] = true;
            backtracking(nums, visited, path);
            path.pop_back();
            visited[i] = false;
        }

        return result;
    }
};
// @lc code=end

