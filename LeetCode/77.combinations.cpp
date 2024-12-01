/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    void backtracking(int n, int k, vector<int> path, int start_index){
        if(path.size() == k){
            result.push_back(path);
        }

        for(int i = start_index; i < n + 1; ++i){
            path.push_back(i);
            backtracking(n, k, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // 时间复杂度O(2^n * k), 空间复杂度O(k)
        // backtracking(n, k, {}, 1);
        // return result;

        // 下面这个方法就避免了遍历，在递归中完成了遍历的操作，实际的复杂度比较复杂
        // 可以比较简单的认为就是O(C(n, k)), 空间复杂度O(n^2)
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](auto&& dfs, int i){
            int d = k - path.size();
            if(d == 0){
                ans.emplace_back(path);
                return;
            }

            if(i > d){
                dfs(dfs, i - 1);
            }

            path.push_back(i);
            dfs(dfs, i - 1);
            path.pop_back();
        };

        dfs(dfs, n);
        return ans;
    }
};
// @lc code=end

