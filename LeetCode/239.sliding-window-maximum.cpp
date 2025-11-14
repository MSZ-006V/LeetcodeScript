/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> mlist;
        // 单调队列，元素从队头到队尾是递减的
        for(int i = 0; i < nums.size(); ++i){
            // input 
            while(!mlist.empty() && nums[mlist.back()] <= nums[i]){
                mlist.pop_back(); // 如果发现队列最后一个元素小于等于，则弹出（相同元素只保留最后一个）
            }
            mlist.push_back(i); // 弹出后，压入对应元素，操作类似单调栈
            // output 
            if(i - mlist.front() >= k){ 
            // 不能使用mlist.size()进行判断，因为不是真实的窗口大小，只有i - mlist.front() 才是真实的窗口大小
            // 因为记录的都是下标，如果队列中元素大于k了，就把最左边的弹出来
            // 表示已经不在窗口里了，没用了所以要弹出
                mlist.pop_front();
            }
            // record ans
            if(i >= k - 1){ // 当窗口大小达到 k 时，才开始记录结果
                ans.push_back(nums[mlist.front()]); // 记录队头的元素
                // 因为是单调队列，所以队头的元素是最大的
            }
        }

        return ans;
    }
};
// @lc code=end

