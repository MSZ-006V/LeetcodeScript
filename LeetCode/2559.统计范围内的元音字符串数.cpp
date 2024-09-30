/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    bool voweJudge(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> diff;
        int pre = 0;
        diff.push_back(pre);
        for(auto word : words){
            if(voweJudge(word[0]) && voweJudge(word[word.size() - 1])){
                pre += 1;
            }
            diff.push_back(pre);
        }
        vector<int> result;
        for(auto query : queries){
            int left = query[0];
            int right = query[1];
            result.push_back(diff[right + 1] - diff[left]);
        }
        return result;
    }
};
// @lc code=end

