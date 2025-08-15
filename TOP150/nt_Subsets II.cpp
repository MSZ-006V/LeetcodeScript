class Solution {
    public:
        void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int> temp_res, int index){
            res.push_back(temp_res);
    
            for(int i = index; i < nums.size(); ++i){
                if(i > index && nums[i] == nums[i - 1]) continue;
                temp_res.push_back(nums[i]);
                backtracking(nums, res, temp_res, i + 1);
                temp_res.pop_back();
            }
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
    
            backtracking(nums, res, {}, 0);
    
            return res;
        }
    };