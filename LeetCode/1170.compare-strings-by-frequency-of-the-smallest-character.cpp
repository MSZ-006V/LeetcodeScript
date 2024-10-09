/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */

// @lc code=start
class Solution {
public:
    int f(string str){
        int cnt = 0;
        char min = 'z';
        for(auto c : str){
            if(c < min){
                min = c;
                cnt = 1;
            }
            else if(c == min){
                cnt++;
            }
        }
        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> query;
        vector<int> word;
        for(auto q : queries){
            query.push_back(f(q));
        }
        for(auto w : words){
            word.push_back(f(w));
        }
        vector<int> result;
        sort(word.begin(), word.end());
        for(auto num : query){
            // 简单的对目标数组排序，然后逐个查找，使用upper_bound，找大于target的第一个数
            int res = word.end() - ranges::upper_bound(word.begin(), word.end(), num);
            result.push_back(res);
        }

        return result;
    }
};
// @lc code=end

