class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        // 差分数组
        map<int, int> diff;
        for(auto l : lights){
            int pos = l[0], range = l[1];
            diff[pos - range]++;
            diff[pos + range + 1]--;
        }

        int pos = 0;
        int val = INT_MIN;
        int sum = 0;
        for(auto [x, delta] : diff){
            sum += delta;
            if(sum > val){
                val = sum;
                pos = x;
            }
        }

        return (int)pos;


        return 0;
    }
};