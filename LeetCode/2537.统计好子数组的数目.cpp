class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // 滑动窗口
        long long ans = 0;
        unordered_map<int, int> ht;
        int left = 0, pair = 0;
        for(int right = 0; right < nums.size(); ++right){
            pair += ht[nums[right]];
            ht[nums[right]]++;
            
            while(pair >= k){
                ht[nums[left]]--;
                pair -= ht[nums[left]];
                left++;
            }
            cout << "left: " << left << endl;
            ans += left;
        }

        return ans;
    }
};