class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        // 差分数组
        vector<int> diff(102, 0);
        for(auto n : nums){
            diff[n[0]]++;
            diff[n[1] + 1]--;
        }

        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < 101; ++i){
            sum += diff[i];
            if(sum > 0) cnt++;
        }

        return cnt;
    }
};