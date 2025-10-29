class Solution {
public:
    // 与nt_Longest Palindromic Substring完全相同，只是多出了一个计数的部分
    // tc O(n^2), sc O(n^2)
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;

        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        dp[i][j] = true; cnt++;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true; cnt++;
                    }
                }
            }
        }

        return cnt;

    }
};

// 也可以使用双指针，有点暴力穷举的样子，时间复杂度相同，只是优化了空间复杂度
// 实际上就是遍历每一个点，从每一个点开始向左右延伸找所有的回文
// tc O(n^2), sc O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += countPali(s, i, i);
            res += countPali(s, i, i + 1);
        }
        return res;
    }

private:
    int countPali(string s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
};

    