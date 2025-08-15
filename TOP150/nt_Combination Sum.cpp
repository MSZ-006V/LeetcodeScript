class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int target, vector<int>& temp, int sum, int index){
        if(sum > target) return;
        if(sum == target){
            res.push_back(temp);
            return;
        }

        for(int i = index; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            backtracking(nums, target, temp, sum + nums[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // optimal method tc O(2^{t/m}), sc O(t/m), t is the given target and m is the minimum value in nums
        sort(nums.begin(), nums.end());
        int sum = 0;
        int index = 0;
        vector<int> tmp;
        backtracking(nums, target, tmp, sum, index);

        return res;
    }
};
