class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<bool>& visited, vector<int> tmp, int n){
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }

        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                tmp.push_back(nums[i]);
                visited[i] = true;
                backtracking(nums, visited, tmp, n);
                visited[i] = false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // tc O(n! * n), sc O(n! * n)
        int n = nums.size();
        vector<bool> visited(n, false);

        backtracking(nums, visited, {}, n);

        return res;
    }
};

// 最优方法，直接调换就可以，可以大幅度减少空间占用，也优雅很多
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};