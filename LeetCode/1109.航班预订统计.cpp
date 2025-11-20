class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for(auto b : bookings){
            diff[b[0] - 1] += b[2];
            diff[b[1]] -= b[2];
        }

        vector<int> res;
        res.push_back(diff[0]);
        int sum = diff[0];
        for(int i = 1; i < n; ++i){
            sum += diff[i];
            res.push_back(sum);
        }

        return res;
    }
};