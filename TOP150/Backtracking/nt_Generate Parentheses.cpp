class Solution {
public:
    vector<string> results;

    void backtracking(int n, string& temp_res, int open, int close){
        if(open == n && close == n){
            results.push_back(temp_res);
            return;
        }

        if(open < n){
            temp_res.push_back('(');
            backtracking(n, temp_res, open + 1, close);
            temp_res.pop_back();
        }
        if(open > close){ // 防止出现左边第一个是 ')' 的情况
            temp_res.push_back(')');
            backtracking(n, temp_res, open, close + 1);
            temp_res.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string temp_res = "";
        backtracking(n, temp_res, 0, 0);

        return results;
    }
};
