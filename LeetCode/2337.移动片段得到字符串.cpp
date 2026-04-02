class Solution {
public:
    bool canChange(string start, string target) {
        string s = start, t = target;
        s.erase(remove(s.begin(), s.end(), '_'), s.end());
        t.erase(remove(t.begin(), t.end(), '_'), t.end());
        if (s != t) {
            return false;
        }
        for (int i = 0, j = 0; i < start.length(); i++) {
            if (start[i] == '_') {
                continue;
            }
            while (target[j] == '_') {
                j++;
            }
            if (i != j && (start[i] == 'L') == (i < j)) {
                return false;
            }
            j++;
        }
        return true;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/move-pieces-to-obtain-a-string/solutions/1658923/nao-jin-ji-zhuan-wan-pythonjavacgo-by-en-9sqt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。