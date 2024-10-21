/*
 * @lc app=leetcode id=1898 lang=cpp
 *
 * [1898] Maximum Number of Removable Characters
 */

// @lc code=start
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ns = s.size();
        int np = p.size();
        int n = removable.size();
        // 辅助函数，用来判断移除 k 个下标后 p 是否是 s_k 的子序列
        auto check = [&](int k) -> bool {
            vector<int> state(ns, 1);   // s 中每个字符的状态
            for (int i = 0; i < k; ++i){
                state[removable[i]] = 0;
            }
            // 匹配 s_k 与 p 
            int j = 0;
            for (int i = 0; i < ns; ++i){ // 双指针方法来判断
                // s[i] 未被删除且与 p[j] 相等时，匹配成功，增加 j
                if (state[i] && s[i] == p[j]){
                    ++j;
                    if (j == np){
                        return true;
                    }
                }
            }
            return false;
        };

        // 二分查找，闭区间查找，查找的范围是removable数组的前n个元素的长度
        // 所以左边界是1，代表只移除1个元素，右边界是整个数组的长度，代表移除所有对应下标的元素
        int left = 1, right = n;
        int ans = 0;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (check(mid)){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

