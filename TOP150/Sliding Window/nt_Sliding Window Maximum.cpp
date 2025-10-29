class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonic queue
        // tc O(n)
        // 如果使用priority_queue，复杂度就是O(nlogn)，每次插入需要O(logn)进行调整
        list<int> mlist;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            while(!mlist.empty() && nums[mlist.back()] <= nums[i]){
                mlist.pop_back();
            }
            mlist.push_back(i);

            if(i - mlist.front() >= k){
                mlist.pop_front();
            }
            if(i >= k - 1){
                result.push_back(nums[mlist.front()]);
            }
        }

        return result;
    }
};
