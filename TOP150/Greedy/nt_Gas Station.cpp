class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_pos = 0;
        int cur_gas = 0;
        int total_gas = 0;

        for(int i = 0; i < cost.size(); ++i){
            int val = -cost[i] + gas[i];
            cur_gas += val;
            total_gas += val;
            if(cur_gas < 0){
                start_pos = i + 1;
                cur_gas = 0;
            }
        }

        return total_gas < 0 ? -1 : start_pos;
    }
};
