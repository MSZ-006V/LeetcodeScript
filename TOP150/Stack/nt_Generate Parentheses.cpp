class Solution {
public:
    // 使用两个变量open和close来记录左括号和右括号的个数
    // 当左括号个数小于n的时候，任何时候可以插入左括号
    // 当open大于close的时候，任何时候可以插入右括号
    // 使用回溯，当open和close等于n的时候，就代表满足了条件，记录

    // tc O($$\frac{4^n}{\sqrt{t}}$$), sc O(n), 时间复杂度是一个卡特兰数的渐近表达
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
        if(open > close){
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
