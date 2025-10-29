class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // tc O(nlogn), because of sort function, sc O(n)
        // 首先对出发位置进行降序排序，然后计算出每个时间，维护一个单调栈，从栈底到栈顶是单调递增的
        // 遍历时间，如果当前遍历到的时间小于等于栈顶的，就说明当前这辆车一定会并入某个car fleet中，就不进栈
        // 否则将会进栈，最后返回栈长度，即为最后一共有几个car fleet
        int n = position.size();
        stack<double> st;
        vector<std::pair<int, int>> ps;
        vector<double> time(n, 0);

        for(int i = 0; i < n; ++i){
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        
        for(int i = 0; i < n; ++i){
            time[i] = (double)(target - ps[i].first) / ps[i].second;
            // cout << time[i] << ' ';
        }

        for(auto& t : time){
            if(!st.empty() && st.top() >= t) continue;
            st.push(t);
        }

        return st.size();
    }
};
