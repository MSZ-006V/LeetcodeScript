/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
private:
    vector<string> result;
public:
    void backtracking(set<string>& wordset, string s, int start_index, vector<string> words){
        if(start_index >= s.size()){
            string output = accumulate(words.begin() + 1, words.end(), words[0], [](const std::string& a, const std::string& b){
                return a + " " + b;
            });
            result.push_back(output);
        }
        
        // i 指的是单词的长度
        for(int i = 1; i <= s.size() - start_index; ++i){
            string sstr = s.substr(start_index, i);
            if(wordset.find(sstr) != wordset.end()){
                words.push_back(sstr);
                backtracking(wordset, s, start_index + i, words);
                words.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordset(wordDict.begin(), wordDict.end());

        backtracking(wordset, s, 0, {});
        return result;
    }
};
// @lc code=end

