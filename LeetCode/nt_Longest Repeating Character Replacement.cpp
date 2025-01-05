class Solution {
public:
    int characterReplacement(string s, int k) {
        // tc O(n)
        // 也是一个滑动窗口问题，因为在某个串中，主要的元素肯定是数量最多的
        // 所以只需要判断当前串中除了主要元素以外的其他的元素的数量，如果大了就缩短右边边界
        unordered_map<char, int> ht;
        int maxLen = 0;
        int left = 0, maxf = 0;
        for(int right = 0; right < s.size(); ++right){
            ht[s[right]]++;
            maxf = max(maxf, ht[s[right]]);

            while(right - left + 1 - maxf > k){ // 如果需要替换的字符数量大于k了，说明invalid，就缩短右边边界
                ht[s[left]]--;
                left++;
            }

            if(right - left + 1 > maxLen){
                maxLen = right - left + 1;
            }
        }

        return maxLen;
    }
};
