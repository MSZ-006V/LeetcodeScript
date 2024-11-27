/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int cnt[121]{};
        for(int age : ages){
            cnt[age]++;
        }
        // 年龄最大就120岁
        // 并且由于下面的这种遍历方式, cnt[age_y]一定小于cnt[age_x]，所以第三个条件一定是假的，不用判断了
        int ans = 0, cnt_window = 0, age_y = 0;
        for(int age_x = 0; age_x < 121; ++age_x){
            cnt_window += cnt[age_x];
            while(age_y * 2 <= age_x + 14){
                cnt_window -= cnt[age_y];
                age_y++;
            }
            if(cnt_window > 0){
                ans = ans + cnt[age_x] * cnt_window - cnt[age_x];
            }
        }

        return ans;
    }
};
// @lc code=end

