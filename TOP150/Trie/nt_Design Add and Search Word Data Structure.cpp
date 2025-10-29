class WordDictionary {
private:
    bool isEnd;
    vector<WordDictionary*> next;
public:
    WordDictionary(): next(26), isEnd(false) {
        
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(auto c : word){
            if(node->next[c - 'a'] == nullptr){
                node->next[c - 'a'] = new WordDictionary();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool dfs(string word, WordDictionary* node, int index){
        for(int i = index; i < word.size(); ++i){
            char c = word[i];
            if(c == '.'){
                for(int j = 0; j < 26; ++j){
                    if(node->next[j] != nullptr && dfs(word, node->next[j], i + 1)){
                        return true;
                    }
                }
                return false;
            }
            else{
                node = node->next[c - 'a'];
                if(node == nullptr) return false;
            }
        }
        return node->isEnd;
    }
    
    bool search(string word) {
        return dfs(word, this, 0);
    }
};
