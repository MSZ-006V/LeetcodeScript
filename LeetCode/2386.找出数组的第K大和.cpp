class Solution {
public:
    // 暴力做法就是生成所有子序列，同时统计和，最后就知道要取哪个了
    long long kSum(vector<int> &nums, int k) {
        long long sum = 0;
        for (int &x : nums) {
            if (x >= 0) {
                sum += x;
            } else {
                x = -x;
            }
        }
        ranges::sort(nums);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0); // 空子序列
        while (--k) {
            auto [s, i] = pq.top();
            pq.pop();
            if (i < nums.size()) {
                // 在子序列的末尾添加 nums[i]
                pq.emplace(s + nums[i], i + 1); // 下一个添加/替换的元素下标为 i+1
                if (i) { // 替换子序列的末尾元素为 nums[i]
                    pq.emplace(s + nums[i] - nums[i - 1], i + 1);
                }
            }
        }
        return sum - pq.top().first;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/find-the-k-sum-of-an-array/solutions/1764389/zhuan-huan-dui-by-endlesscheng-8yiq/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。