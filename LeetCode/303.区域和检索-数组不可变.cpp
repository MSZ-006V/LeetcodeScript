/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
private:
    vector<int> diff;
public:
    NumArray(vector<int>& nums) {
        diff.push_back(0);
        int pre = 0;
        for(auto& num : nums){
            pre += num;
            diff.push_back(pre);
        }
        for(auto num : diff){
            cout << num << ' ';
        }
    }
    
    int sumRange(int left, int right) {
        return diff[right + 1] - diff[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

