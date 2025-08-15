// bf method, tc O(n^2), sc O(1)
class Solution {
public:
    bool check(vector<vector<char>>& board, int x, int y){
        unordered_set<int> nums;
        for(int i = x; i < x + 3; ++i){
            for(int j = y; j < y + 3; ++j){
                if(board[i][j] == '.') continue;
                if(nums.find(board[i][j]) != nums.end()){
                    return false;
                }
                nums.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            unordered_set<int> nums;
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                if(nums.find(board[i][j]) != nums.end()){
                    return false;
                }
                nums.insert(board[i][j]);
            }
        }

        for(int j = 0; j < 9; ++j){
            unordered_set<int> nums;
            for(int i = 0; i < 9; ++i){
                if(board[i][j] == '.') continue;
                if(nums.find(board[i][j]) != nums.end()){
                    return false;
                }
                nums.insert(board[i][j]);
            }
        }

        for(int i = 0; i < 7; i += 3){
            for(int j = 0; j < 7; j += 3){
                if(!check(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};
