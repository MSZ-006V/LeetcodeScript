/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for(auto num : arr1){
            unsigned p = lower_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
            // cout << arr2[p] << endl;
            bool ok = true;
            if (p < arr2.size()) { // arr2[p]是大于num的第一个数
                ok &= (arr2[p] - num > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) { // arr2[p - 1]是小于num的第一个数
                ok &= (num - arr2[p - 1] > d);
            }
            cout << arr2[p] << ' ' << arr2[p - 1] << endl;
            cnt += ok;
        }
        return cnt;
    }
};
// @lc code=end

