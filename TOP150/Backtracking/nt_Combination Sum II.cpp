class Solution {
public:
    // 直接利用set暴力去重，会增加额外的时间复杂度
    set<vector<int>> res;
    void backtracking(vector<int>& nums, int target, vector<int>& temp, int sum, int index){
        // if(index > 1 && nums[index] == nums[index - 1]){
        //     cout << "return val: " << nums[index] << endl;
        //     return;
        // }
        if(sum > target) return;
        if(sum == target){
            res.insert(temp);
            return;
        }

        for(int i = index; i < nums.size(); ++i){
            
            // if(i > index && nums[i] == nums[i - 1]) continue; 加这个去重就可以
            // 比如数组[1,2,2,5]， 已经得到一个结果数组是[1,2,5]，在遍历到第二个2的时候，这时候tmp数组是[1], 这时候就会触发这个语句，跳过第二个2，
            // 总之效果就是跳过重复的数，免得重复放入元素
            // 用这种方式去重就可以不用set，最优方法optimal

            temp.push_back(nums[i]);
            backtracking(nums, target, temp, sum + nums[i], i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        int index = 0;
        vector<int> tmp;
        backtracking(candidates, target, tmp, sum, index);

        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};

