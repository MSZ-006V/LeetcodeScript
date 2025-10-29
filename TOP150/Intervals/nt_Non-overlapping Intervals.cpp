class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // leetcode 435 无重叠区间
        // 按照区间的结束位置进行排序，然后贪心选择不重叠的区间
        // 我们希望每次选择“结束时间最早”的区间，因为它 留给后面区间的空间最多，从而能让后面保留更多不重叠的区间
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        for(auto i : intervals){
            cout << i[0] << ' ' << i[1] << endl;
        }
        int delete_num = 0;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] < intervals[i - 1][1]){ // 有这种情况，就是重叠了，所以删除个数+1
                delete_num++;
                cout << "remove: " << intervals[i][0] << ' ' << intervals[i][1] << endl;
                intervals[i][1] = intervals[i - 1][1]; // 把前一个的小范围复制到后面大范围的，使后一个大范围的减小，便于后面进行判断
            }
        }
        return delete_num;
    }
};
