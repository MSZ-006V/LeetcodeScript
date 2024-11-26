/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Trie {
private:
    bool IsEnd; // 代表这个节点是不是一个字符串的结尾。若是，从此节点到根节点构成一个字符串
    Trie* next[26]; // 每一个节点存储的next数组
public:
    Trie(){
        IsEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word){ // 向字典树中插入一个单词word
        Trie* node = this;
        for(char c : word){ // 按照单词正顺序插入的，也可以逆顺序插入
            if(node->next[c - 'a'] == NULL){
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->IsEnd = true; // 代表是一个结尾
    }

    int search(string word) { // 查找树中有没有word这个完整的单词
        Trie* node = this;
        int index = 0;
        while(node->IsEnd == false && index < word.size()){
            node = node->next[word[index] - 'a'];
            if(node == nullptr){
                return 0;
            }
            index++;
        }
        // cout << word.substr(0, index) << endl;
        return index; // 循环结束，说明不能继续往下找了，也就是找到了word的最长前缀的下标了
    }

};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string word : dictionary){ // 首先把字典dictionary中所有词放入trie树种
            trie.insert(word);
        }

        std::vector<std::string> words; // 分割字符串
        size_t pos = 0, found;
        while ((found = sentence.find(' ', pos)) != std::string::npos) {
            words.push_back(sentence.substr(pos, found - pos));
            pos = found + 1;
        }
        
        words.push_back(sentence.substr(pos)); // words数组中存放所有字符

        vector<string> result_words;
        for(auto word : words){
            int index = trie.search(word); // 用完整版的单词进行查找
            if(index != 0){ // 返回不为0，说明trie前缀树中有一部分这个词的前缀，就取子串，然后放入结果就行
                result_words.push_back(word.substr(0, index));
            }
            else{// 如果返回是0，说明完全没有，这个词无法被替换，也就是在trie树中没有这个词的前缀
                result_words.push_back(word);
            }
        }

        string result_str = ""; // 再把字符串全部连起来
        result_str = accumulate(result_words.begin() + 1, result_words.end(), result_words[0], [](auto a, auto b){
            return a + " " + b;
        });

        return result_str;
    }
};
// @lc code=end

