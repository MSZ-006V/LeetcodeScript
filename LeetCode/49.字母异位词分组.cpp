/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordmap;
        for(int i = 0; i < strs.size(); ++i){
            string word_key = strs[i];
            sort(word_key.begin(), word_key.end(),[](char a, char b){
                return a < b;
            });
            wordmap[word_key].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(const auto& pair:wordmap){
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

