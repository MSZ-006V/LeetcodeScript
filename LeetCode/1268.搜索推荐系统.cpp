struct Trie {
    unordered_map<char, Trie*> child;
    priority_queue<string> words;
};

class Solution {
private:
    void addWord(Trie* root, const string& word) {
        Trie* cur = root;
        for (const char& ch: word) {
            if (!cur->child.count(ch)) {
                cur->child[ch] = new Trie();
            }
            cur = cur->child[ch];
            cur->words.push(word);
            if (cur->words.size() > 3) {
                cur->words.pop();
            }
        }
    }
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for (const string& word: products) {
            addWord(root, word);
        }
        
        vector<vector<string>> ans;
        Trie* cur = root;
        bool flag = false;
        for (const char& ch: searchWord) {
            if (flag || !cur->child.count(ch)) {
                ans.emplace_back();
                flag = true;
            }
            else {
                cur = cur->child[ch];
                vector<string> selects;
                while (!cur->words.empty()) {
                    selects.push_back(cur->words.top());
                    cur->words.pop();
                }
                reverse(selects.begin(), selects.end());
                ans.push_back(move(selects));
            }
        }
        
        return ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/search-suggestions-system/solutions/101822/suo-tui-jian-xi-tong-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。