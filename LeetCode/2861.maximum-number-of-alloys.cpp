/*
 * @lc app=leetcode id=2861 lang=cpp
 *
 * [2861] Maximum Number of Alloys
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        // 这个题解太巧妙了，灵神题解
        // https://leetcode.cn/problems/maximum-number-of-alloys/solutions/2446024/er-fen-da-an-fu-ti-dan-by-endlesscheng-3jdr/
        // 分析如下，最优惠的方案其实是使用一台机器不停的制造，所以不会出现一台机器造一点另一台机器造一点的情况
        // 所以这个问题可以转化为有限预算下，一台机器可以造的最大合金数量，这个数量从0到某上限，有单调性，所以可以二分
        // 所以只需要遍历每一台机器，计算每一台机器可以生产的最大合金数量，然后记录就可以了
        
        int ans = 0;
        int mx = *min_element(stock.begin(), stock.end()) + budget;
        for(auto &comp : composition){
            auto check = [&](long long num) -> bool{
                long long money = 0;
                for(int i = 0; i < n; ++i){
                    if(stock[i] < comp[i] * num){
                        money += (comp[i] * num - stock[i]) * cost[i]; // 如果库存不够，那就把制造当前数量合金需求的合金减去库存，求出要花的钱
                        if(money > budget){ // 然后与预算进行比较大小
                            return false;
                        }
                    }
                }
                return true;
            };
            // 闭区间写法，这里有个巧妙的地方，让left = ans, 紧缩二分搜索的区间，后续制造合金数量更小的机器可以更快地跳过，而不是从0继续开始找
            // 因为制造数量更小是没有意义的，不用看
            int left = ans, right = mx; // 闭区间写法，这里有个巧妙的地方
            int tans = 0;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(check(mid)){
                    left = mid + 1;
                    tans = mid;
                }
                else{
                    right = mid - 1;
                }
            }
            ans = max(ans, tans); // 最后记录比较大小就可以了，取最大的max()就可以，用灵神的还可以击败100%
        }
        return ans;
    }
};
// @lc code=end

