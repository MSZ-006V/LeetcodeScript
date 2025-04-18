/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    bool isEnd; // 代表这个节点是否是一个字符串的结尾
    Trie* next[26];
    // 每一个前缀树的节点都包含上面这两个
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c : word){
            if(node->next[c - 'a'] == NULL){ // 如果没有就创建一个新的
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word){
            node = node->next[c - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return node->isEnd; // 如果遍历word完，此时node不是结尾的话，返回就是false了，否则会返回true
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix){
            node = node->next[c - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

