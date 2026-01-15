class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // tc O(n), sc O(n)
        int n = nums.size();
        stack<int> st;
        // 栈是单调递减栈
        int k = INT_MIN;
        for(int i = n - 1; i >= 0; --i){
            if(nums[i] < k) return true;
            while(!st.empty() && st.top() < nums[i]){
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};