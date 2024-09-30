/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 很巧妙的方法，利用了桶思想
        int len = tasks.size();
        vector<int> vec = vector<int>(26, 0);
        for(auto c:tasks){
            vec[c - 'A']++;
        }
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            return a > b;
        });
        // 此时vec[0]是任务数量最多的那个数
        // 下面要统计有几种任务和最多的任务相等，比如6个A, 6个B，6个C之类的，如果是这种情况，cnt=3
        int cnt = 1; // 统计vec中，还有几种任务的数量和vec[0]相等的
        while(cnt < 26 && vec[cnt] == vec[0]) cnt++;

        int num1 = len; // 情况1，完成时间最短就是任务个数
        int num2 = (vec[0] - 1) * (n + 1) + cnt; // 情况2，利用桶思想合理安排的最短时间

        return max(num1, num2);
    }
};
// @lc code=end

