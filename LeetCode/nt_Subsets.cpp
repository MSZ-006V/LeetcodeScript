class Solution {
public:
    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int> temp_res, int index){
        res.push_back(temp_res);

        for(int i = index; i < nums.size(); ++i){
            temp_res.push_back(nums[i]);
            backtracking(nums, res, temp_res, i + 1);
            temp_res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // tc O(n * 2^n), sc O(n)
        vector<vector<int>> res;

        backtracking(nums, res, {}, 0);

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