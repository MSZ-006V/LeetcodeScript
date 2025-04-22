// 给定一个数字集合 nums 和一个上界数字 n，找出比 n 小的最大数，这个数只能由 nums 中的数字组成
// nums = {2, 4, 9}
// n = 23121
// output = 22999

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string res = "";
    vector<char> digits;

    bool dfs(string& nStr, string path, int pos, bool limit) {
        if (pos == nStr.size()) {
            if (res == "" || path > res) res = path;
            return true;
        }

        bool found = false;
        char up = limit ? nStr[pos] : '9'; // 如果没有限制，直接用最大的就可以

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] > up) continue;
            
            // 确定下一个数位有没有限制（是否可以直接用最大数来填充）
            // 如果等于并且上一个有限制，那下一个还是有限制
            // 如果小于，那下一个就没有限制了
            // 如果等于，但是没有限制，那下一个也不用限制
            bool nextLimit = (limit && digits[i] == up); 
            if (dfs(nStr, path + digits[i], pos + 1, nextLimit)) {
                found = true;
                break; // 找到了就直接返回
            }
        }

        return found;
    }

    string maxNumberLessThanN(vector<int>& nums, int n) {
        string nStr = to_string(n);
        for (int num : nums) digits.push_back(num + '0');
        sort(digits.begin(), digits.end());

        // 优先尝试等长解
        if (dfs(nStr, "", 0, true)) return res;

        // 如果不行，尝试长度减1的全排列填满，直接用最大的来填满就可以
        string shorter(nStr.size() - 1, digits.back());
        return shorter;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 4, 9};
    int n = 233212;
    cout << sol.maxNumberLessThanN(nums, n) << endl; // 输出 22999
    return 0;
}
