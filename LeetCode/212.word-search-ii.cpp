/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
struct Trienode{
    string word;
    vector<Trienode*> next;
    Trienode(): word(""), next(26, nullptr) {}
};

void InsertTrie(Trienode* root, string word){
    // Trienode* node = this; 也可以使用this指针
    Trienode* node = root;
    for(auto c : word){
        if(node->next[c - 'a'] == nullptr){
            node->next[c - 'a'] = new Trienode();
        }
        node = node->next[c - 'a'];
    }
    node->word = word;
}

class Solution {
    int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    int n;
    int m;
public:
    void dfs(vector<vector<char>>& board, int x, int y, Trienode* root, set<string>& res){
        char ch = board[x][y];
        if(root->next[ch - 'a'] == nullptr) return;

        root = root->next[ch - 'a'];
        if(root->word.size() > 0){
            res.insert(root->word);
        }

        board[x][y] = '#'; // 这一句实际上是回溯的功能，记录访问过了
        for(int i = 0; i < 4; ++i){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];

            if(next_x >= 0 && next_y >= 0 && next_x < n && next_y < m){
                if(board[next_x][next_y] != '#'){
                    dfs(board, next_x, next_y, root, res);
                }
            }
        }
        board[x][y] = ch; // 回溯，恢复原来的，以便于以后还可以继续查找
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        Trienode* root = new Trienode();
        set<string> res;

        for(auto word : words){
            InsertTrie(root, word);
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(root->next[board[i][j] - 'a'] != nullptr){
                    dfs(board, i, j, root, res);
                }
            }
        }
        
        vector<string> result;
        for(auto& word : res){
            result.push_back(word);
        }
        return result;
    }
};
// @lc code=end

