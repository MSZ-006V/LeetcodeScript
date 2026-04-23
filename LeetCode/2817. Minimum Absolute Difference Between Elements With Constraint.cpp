class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        set<int> s = {INT_MIN / 2, INT_MAX};
        for (int i = x; i < nums.size(); ++i) {
            s.insert(nums[i - x]);
            int y = nums[i];
            auto it = s.lower_bound(y); // 注意一定要这么写，不要写lower_bound(s.begin(), s.end(), y), 
            // 否则单是这一句的时间复杂度就是O(nlogn)，循环n次后整个算法时间复杂度会变为O(n^2logn）
            ans = min(ans, min(*it - y, y - *--it)); // 比较y的左边邻居和右边邻居，同时也能够省掉abs()
        }

        return ans;
    }
};