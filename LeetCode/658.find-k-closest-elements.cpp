/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [&x](int a, int b){
            return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
        };
        // 可以按照题目的规则，把符合条件的数进行排序，按照cmp写的规则，最接近的数越前
        // 所以结果这么排序后，最接近的数字就是第一个，然后再从arr中取出k个数就可以了
        sort(arr.begin(), arr.end(), cmp);
        sort(arr.begin(), arr.begin() + k, [](int a, int b){ // 只排序前面的就可以了
            return a < b;
        });

        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
// @lc code=end

