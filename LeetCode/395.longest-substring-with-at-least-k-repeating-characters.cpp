/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k) return 0;

        unordered_set<char> chars(s.begin(), s.end());
        unordered_map<char, int> charcounter;
        for(char c : s){
            charcounter[c]++;
        }

        for(char c : chars){
            vector<string> t;
            if(charcounter[c] < k){
                // 这一段之所以里面写一个return，是因为如果字符串s里面某个字符c的出现次数少于k
                // 那么把c作为分割符，分割s后得到的子串集合，要找的目标一定在某个子串里面
                // 不需要考虑其他出现次数少于k的字符，因为这些字符会在下面更深层次的递归中进行考虑
                // 所以最后一定可以考虑到所有的出现次数少于k的字符。因为最终目标的子串，一定在把这些
                // 出现次数少于k次的字符作为分隔符，分割s后得到的子串集合中，某一个子串里面，在一个层次的递归中
                // 考虑一个出现次数少于k次的字符就可以了
                split(s, t, c);
                int res = 0;
                for(string tn : t){
                    res = max(res, longestSubstring(tn, k));
                }
                return res;
            }
        }

        return s.size();
    }

    void split(string& s, vector<string>& t, const char c = ' '){
        t.clear();
        istringstream iss(s);
        string temp;
        while(getline(iss, temp, c)){
            t.push_back(temp);
        }
    }
};
// @lc code=end

