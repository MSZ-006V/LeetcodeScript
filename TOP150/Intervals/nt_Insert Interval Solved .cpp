class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // tc: O(NlogN) sc: O(N)
        // 优化点：可以使用二分法找到插入位置，减少排序时间
        // 因为排序的时间复杂度是O(NlogN)，而插入位置可以用O(logN)找到
        intervals.push_back(newInterval);
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
