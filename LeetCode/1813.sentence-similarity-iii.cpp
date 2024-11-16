/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 */

// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // 两个句子sentence1和 sentence2，如果是相似的，那么这两个句子按空格分割得到的
        // 字符串数组words1和words2一定能通过往其中一个字符串数组中插入某个字符串
        // 数组(可以为空)，得到另一个字符串数组。这个验证可以通过双指针完成。i表示两个
        // 字符串数组从左开始，最多有i个字符串相同。j表示剩下的字符串数组从右开始，
        // 最多有j个字符串相同。如果i+j正好是某个字符串数组的长度，那么原字符串就是相似的
        vector<string> s1;
        vector<string> s2;
        size_t start = 0, end;
        while((end = sentence1.find(' ', start)) != std::string::npos){
            s1.push_back(sentence1.substr(start, end - start));
            start = end + 1;
        }
        s1.push_back(sentence1.substr(start));

        start = 0;
        while((end = sentence2.find(' ', start)) != std::string::npos){
            s2.push_back(sentence2.substr(start, end - start));
            start = end + 1;
        }
        s2.push_back(sentence2.substr(start));

        int i = 0, j = 0;
        while(i < s1.size() && i < s2.size() && s1[i] == s2[i]){
            i += 1;
        }
        while(j < s1.size() - i && j < s2.size() - i && s1[s1.size() - 1 - j] == s2[s2.size() - 1 - j]){
            j += 1;
        }
        return (i + j) == min(s1.size(), s2.size())?true:false;
    }
};
// @lc code=end

