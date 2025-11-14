class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n + 2, 0); // 避免讨论复杂的下标出界情况
        vector<int> results;
        int cnt = 0;
        for(auto q : queries){
            int idx = q[0] + 1, c = q[1];

            if(colors[idx]) cnt -= (colors[idx] == colors[idx - 1]) + (colors[idx] == colors[idx + 1]);
            colors[idx] = c;
            cnt += (colors[idx] == colors[idx - 1]) + (colors[idx] == colors[idx + 1]);
            results.push_back(cnt);
        }

        return results;
    }
};