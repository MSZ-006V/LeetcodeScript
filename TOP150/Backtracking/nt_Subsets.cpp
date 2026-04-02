class Solution {
public:
    // 注意这里加了 &，变成了按引用传递
    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp_res, int index) {
        res.push_back(temp_res); // 这里依然是 O(n) 的深拷贝，存入最终结果

        for (int i = index; i < nums.size(); ++i) {
            temp_res.push_back(nums[i]);       // 做选择
            backtracking(nums, res, temp_res, i + 1); // 带着同一个 temp_res 深入
            temp_res.pop_back();               // 撤销选择（因为是引用，必须手动恢复现场！）
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // tc O(n * 2^n), sc O(n)
        vector<vector<int>> res;
        vector<int> temp_res;

        backtracking(nums, res, temp_res, 0);

        return res;
    }
};

vector<vector<int>> subsets(vector<int>& nums) {
    // 这个也可以实现，相当于每次循环次数不停地按照2的幂次方递增，2 -> 4 -> 8
    // 数组中有3个元素，那么子集就有2^3个
    vector<vector<int>> res = {{}};
    
    for (int num : nums) {
        int size = res.size();
        for (int i = 0; i < size; i++) {
            vector<int> subset = res[i];
            subset.push_back(num);
            res.push_back(subset);
        }
    }

    return res;
}