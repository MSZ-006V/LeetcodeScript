class Solution {
public:
    double distance(int x1, int y1){
        return sqrt(pow(x1, 2) + pow(y1, 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // tc O(n * logn), sc O(n)
        auto cmp = [](pair<double, int> a, pair<double, int> b){
            return a.first > b.first;
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> pq(cmp);

        for(int i = 0; i < points.size(); ++i){
            double dis = distance(points[i][0], points[i][1]);
            pq.push({dis, i});
        }

        vector<vector<int>> res;
        while(k-- > 0){
            auto cur = pq.top(); pq.pop();
            res.push_back(points[cur.second]);
        }

        return res;
    }
};
