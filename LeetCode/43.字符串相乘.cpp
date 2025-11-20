/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int m = num1.size(), n = num2.size();
        vector<int> ansarr = vector<int>(m + n, 0);
        for(int i = m - 1; i >= 0; --i){ // 按照乘法规则相乘
            int x = num1[i] - '0';
            for(int j = n - 1; j >= 0; --j){
                int y = num2[j] - '0';
                ansarr[i + j + 1] += x * y;
            }
        }
        for(int i = m + n - 1; i > 0; --i){ // 处理每一位的进位
            ansarr[i - 1] += ansarr[i] / 10; // 前一位加上进位
            ansarr[i] %= 10; // %10保证一个位置只有一个个位数
        }

        string res;
        for(int i = 0; i < m + n; ++i){
            if(i == 0 && ansarr[i] == 0) continue;
            res += ansarr[i] + '0';
        }
        return res;
    }
};
// @lc code=end

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> ans = vector(m + n, 0);
        for(int i = n - 1; i >= 0; --i){
            int x = num1[i] - '0';
            for(int j = m - 1; j >= 0; --j){
                int y = num2[j] - '0';
                ans[i + j + 1] += x * y;
            }
        }

        for(int i = m + n - 1; i > 0; --i){
            ans[i - 1] += ans[i] / 10;
            ans[i] %= 10;
        }


    }
};
