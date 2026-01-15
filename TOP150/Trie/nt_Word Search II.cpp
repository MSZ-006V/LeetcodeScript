struct trie{
    string word;
    vector<trie*> next;
    trie(): word(""), next(26) {}
};

void insert(trie* root, string word){
    trie* node = root;
    for(auto c : word){
        if(node->next[c - 'a'] == nullptr){
            node->next[c - 'a'] = new trie();
        }
        node = node->next[c - 'a'];
    }
    node->word = word;
}

// leetcode 212 word search II
// leetcode 79 word search I
class Solution {
private:
    int m;
    int n;
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
public:
    void dfs(vector<vector<char>>& board, int x, int y, trie* root, set<string>& res){
        char ch = board[x][y];
        if(root->next[ch - 'a'] == nullptr) return;

        root = root->next[ch - 'a'];
        if(root->word.size() > 0){
            res.insert(root->word);
        }

        board[x][y] = '#';
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(board[nx][ny] != '#'){
                    dfs(board, nx, ny, root, res);
                }
            }
        }
        board[x][y] = ch;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        trie* root = new trie();
        set<string> res;

        for(auto word : words){
            insert(root, word);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(root->next[board[i][j] - 'a'] != nullptr){
                    dfs(board, i, j, root, res);
                }
            }
        }

        vector<string> result(res.begin(), res.end());
        return result;
    }
};
