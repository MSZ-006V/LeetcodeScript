// leetcode 139单词拆分，140单词拆分ii
class trie{
private:
    bool isEnd;
    vector<trie*> next;
public:
    trie(): isEnd(false), next(26) {}

    void insert(string word){
        trie* node = this;
        for(char c : word){
            if(node->next[c - 'a'] == nullptr){
                node->next[c - 'a'] = new trie();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    // 如果这个词不是一个完整的词，就返回false，因为找到的不能是某个前缀
    bool search(string &s, int i, int j){
        trie* node = this;
        for(int idx = i; idx <= j; ++idx){
            node = node->next[s[idx] - 'a'];
            if(node == nullptr) return false;
        }
        return node->isEnd;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        trie root;
        int max_len = 0;
        for(auto word : wordDict){
            max_len = max(max_len, (int)word.size()); // .size() return size_t 类型，所以必须转换
            root.insert(word);
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        cout << max_len;

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < min(n, i + max_len); ++j){ // 找一个最小值作为范围，同时也避免检查太长的单词
                if(root.search(s, i, j)){
                    dp[i] = dp[j + 1]; // 如果 s[i:j] 是有效单词，并且 dp[j + 1] 也为 true，说明 s[i:n] 可以被拆分，因此 dp[i] = true
                    if(dp[i]) break; // 一旦 dp[i] 为 true，意味着从 i 开始的字符串已经找到了一个有效的拆分方案，没必要继续检查更多的 j，所以直接 break
                }
            }
        }

        return dp[0];
    }
};

// dp方法

    
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i < n + 1; ++i){
            for(auto word : wordDict){
                if(i >= (int)word.size()){
                    dp[i] = (dp[i] || (dp[i - (int)word.size()] && word == s.substr(i - (int)word.size(), (int)word.size())));
                }
            }
        }

        return dp[n];
    }
};
