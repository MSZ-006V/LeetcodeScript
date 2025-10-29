class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[0] < b[0];
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> res;

        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= right){
                right = max(intervals[i][1], right);
            }
            else{
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.push_back({left, right});

        return res;
    }
};
// 似乎有一个greedy的版本，可以做到tc O(n + m), sc O(n)