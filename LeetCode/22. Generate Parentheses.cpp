class Solution {
public:
    vector<string> res;
    void backtracking(int n, string temp_p, int open_p, int close_p){
        if(close_p == n){
            res.push_back(temp_p);
        }

        if(open_p < n){
            backtracking(n, temp_p + "(", open_p + 1, close_p);
        }
        if(close_p < open_p){
            backtracking(n, temp_p + ")", open_p, close_p + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtracking(n, "(", 1, 0);

        return res;
    }
};