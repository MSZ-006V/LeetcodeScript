class Solution {
public:
    // 适用场景：按照题目要求，数组会被分割成若干组，每一组的判断/处理逻辑是相同的。

    // 核心思想：

    // 外层循环负责遍历组之前的准备工作（记录开始位置），和遍历组之后的统计工作（更新答案）。
    // 内层循环负责遍历组，找出这一组最远在哪结束。
    // 这个写法的好处是，各个逻辑块分工明确，也不需要特判最后一组（易错点）。以我的经验，这个写法是所有写法中最不容易出 bug 的，推荐大家记住。
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto join = [&](int start, int end, const string& sep) -> string {
            string res;
            for (int i = start; i < end; i++) {
                if (i > start) {
                    res += sep;
                }
                res += words[i];
            }
            return res;
        };

        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n;) {
            int start = i; // 这一行第一个单词的下标
            int sum_len = words[i].size(); // 第一个单词的长度
            for (i++; i < n && sum_len + words[i].size() + 1 <= maxWidth; i++) {
                sum_len += words[i].size() + 1; // 单词之间至少要有一个空格
            }

            int extra_spaces = maxWidth - sum_len; // 这一行剩余未分配的空格个数
            int gaps = i - start - 1; // 这一行单词之间的空隙个数（单词个数减一）

            // 特殊情况：如果只有一个单词，或者是最后一行，那么左对齐，末尾补空格
            if (gaps == 0 || i == n) {
                string row = join(start, i, " ");
                row += string(extra_spaces, ' '); // 末尾补空格
                ans.push_back(move(row));
                continue;
            }

            // 一般情况：把 extra_spaces 个空格均匀分配到 gaps 个空隙中（靠左的空格更多）
            int avg = extra_spaces / gaps;
            int rem = extra_spaces % gaps;
            string spaces(avg + 1, ' '); // +1 表示加上单词之间已有的一个空格
            string row = join(start, start + rem + 1, spaces + " "); // 前 rem 个空隙多一个空格
            row += spaces;
            row += join(start + rem + 1, i, spaces);
            ans.push_back(move(row));
        }
        return ans;
    }
};
