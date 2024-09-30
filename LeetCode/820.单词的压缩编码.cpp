/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

// @lc code=start
class Trie {
public:
    Trie* next[26];
    Trie() {
        memset(next, 0, sizeof(next));
    }

    void insert(string word){
        Trie* node = this;
        for(int i = word.size() - 1; i >= 0; --i){
            if(node->next[word[i] - 'a'] == NULL){
                node->next[word[i] - 'a'] = new Trie();
            }
            node = node->next[word[i] - 'a'];
        }
    }
};
class Solution {
public:
    int sum;
    void traversal(Trie* trie, int val){
        bool isAllNull = true;
        for(int i = 0; i < 26; ++i){
            if(trie->next[i] != NULL){
                isAllNull = false;
            }
        }

        if(isAllNull){
            sum = sum + val + 1;
            return;
        }
        
        for(int i = 0; i < 26; ++i){
            if(trie->next[i] != NULL){
                traversal(trie->next[i], val + 1);
            }
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        // 前缀树（Trie树经典例题）
        Trie* trie = new Trie();
        for(int i = 0; i < words.size(); ++i){
            trie->insert(words[i]);
        }
        sum = 0;
        traversal(trie, 0);
        return sum;
    }
};
// @lc code=end

