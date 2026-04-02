#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> LetterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        vector<string> result;
        // 预分配长度，避免递归中频繁改变 string 长度
        string path(digits.length(), ' ');

        Dfs(0, digits, path, result);
        return result;
    }

private:
    // 1. 常量命名使用 kPascalCase
    static constexpr const char *kMapping[] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // 2. 核心辅助函数：使用大驼峰命名
    void Dfs(int index, const string &digits, string &path, vector<string> &result)
    {
        // 终止条件：填满了 path 的每一个位置
        if (index == digits.length())
        {
            result.push_back(path);
            return;
        }

        // 取出当前数字对应的字母表
        const string letters = kMapping[digits[index] - '0'];
        for (char c : letters)
        {
            path[index] = c;                      // 直接覆盖当前位置的字符
            Dfs(index + 1, digits, path, result); // 递归处理下一个位置
                                                  // 注意：这里不需要显式回溯（如 path.pop_back），因为下一轮循环会直接覆盖 path[index]
        }
    }
};