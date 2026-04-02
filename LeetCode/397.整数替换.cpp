class Solution
{
private:
    // 使用 unordered_map 解决 vector 空间浪费问题
    unordered_map<long long, int> memo_;

public:
    int integerReplacement(int n)
    {
        return Helper(static_cast<long long>(n));
    }

private:
    int Helper(long long n)
    {
        if (n == 1)
            return 0;
        // 如果算过了，直接返回
        if (memo_.find(n) != memo_.end())
            return memo_[n];

        int res;
        if (n % 2 == 0)
        {
            res = 1 + Helper(n / 2);
        }
        else
        {
            // 奇数时，尝试 +1 和 -1，取步数少的
            res = 1 + min(Helper(n + 1), Helper(n - 1));
        }
        return memo_[n] = res;
    }
};