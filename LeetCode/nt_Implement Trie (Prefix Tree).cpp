// leetcode 208
class PrefixTree {
private:
    vector<PrefixTree*> next;
    bool isEnd;
public:
    PrefixTree(): next(26), isEnd(false) {}
    
    void insert(string word) {
        PrefixTree* node = this;
        for(char c : word){
            if(node->next[c - 'a'] == nullptr){
                node->next[c - 'a'] = new PrefixTree();
            }
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* node = this;
        for(char c : word){
            node = node->next[c - 'a'];
            if(node == nullptr) return false;
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for(char c : prefix){
            node = node->next[c - 'a'];
            if(node == nullptr) return false;
        }
        return true;
    }
};
