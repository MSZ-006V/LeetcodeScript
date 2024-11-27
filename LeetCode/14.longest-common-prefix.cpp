/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class trie{
private:
    vector<trie*> next;
    bool isEnd;
public:
    trie(): isEnd(false), next(26) {}

    void insert(string word){
        trie* node = this;
        for(auto c : word){
            if(node->next[c - 'a'] == nullptr){
                node->next[c - 'a'] = new trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    int search(string word){
        trie* node = this;
        int index = 0;
        for(auto c : word){
            node = node->next[c - 'a'];
            if(node == nullptr){
                return index;
            }
            index++;
        }
        return index;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie* node = new trie();
        node->insert(strs[0]);
        int ans = INT_MAX;
        for(int i = 1; i < strs.size(); ++i){
            int res = node->search(strs[i]);
            ans = min(ans, res);
        }

        return strs[0].substr(0, ans);
    }
};
// @lc code=end

