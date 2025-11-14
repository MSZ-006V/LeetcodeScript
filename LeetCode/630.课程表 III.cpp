class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 可反悔的贪心算法
        // 
        sort(courses.begin(), courses.end(), [](auto a, auto b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;

        int cur_c = 0;
        int cur_day = 0;
        for(int i = 0; i < courses.size(); ++i){
            if(cur_day + courses[i][0] <= courses[i][1]){ // 未超过ddl
                cur_day += courses[i][0];
                cur_c++;
                pq.push(courses[i][0]);
            }
            else if(!pq.empty() && courses[i][0] < pq.top()){
                // 反悔，不上某个课了，改为上目前的课
                cur_day = cur_day - pq.top() + courses[i][0];
                pq.pop(); // 弹出不上的课
                pq.push(courses[i][0]); // 压入要上的课
            }
        }

        return cur_c;
    }
};