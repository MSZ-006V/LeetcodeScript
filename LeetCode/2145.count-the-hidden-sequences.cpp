/*
 * @lc app=leetcode id=2145 lang=cpp
 *
 * [2145] Count the Hidden Sequences
 */

// @lc code=start
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // 2024.9.29 有bug，修不好
        // 针对这个用例过不了[-40], lower = -46, upper = 53, 正确答案应该是60，但是输出是100
        
        // unordered_map<int, int> ht;
        // ht[0] = 1;
        // int max_v = 0, min_v = 100000;
        // int sum = 0, min_index = 0, max_index = 0;
        // for(int i = 0; i < differences.size(); ++i){
        //     sum += differences[i];
        //     for(auto pair : ht){
        //         if(sum - pair.first > max_v){
        //             max_index = i;
        //             max_v = sum - pair.first;
        //         }
        //         if(sum - pair.first < min_v){
        //             min_index = i;
        //             min_v = sum - pair.first;
        //         }
        //     }
        //     ht[sum]++;
        // }
        // for(int i = max_index; i >= 0; --i){
        //     upper = upper - differences[i];
        // }
        // for(int i = min_index; i >= 0; --i){
        //     lower = lower - differences[i];
        // }
        // cout << max_index << ' ' << min_index << endl;
        // cout << upper << ' ' << lower;
        // int ans = upper - lower + 1;
        // if(ans <= 0){
        //     return 0;
        // }
        // else{
        //     return ans;
        // }

        int x = 0, y = 0, sum = 0;
        for(auto num : differences){
            sum += num;
            x = min(x, sum);
            y = max(y, sum);
            if((upper - lower) - (y - x) + 1 < 0) return 0;
        }
        return (upper - lower) - (y - x) + 1;
    }
};
// @lc code=end

