class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int prev_index = 0;
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            index = (i >= 1 && nums[i] == nums[i - 1])? prev_index : 0;
            prev_index
        }
    }
};
