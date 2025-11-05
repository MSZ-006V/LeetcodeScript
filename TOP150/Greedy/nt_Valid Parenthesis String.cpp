
class Solution {
public:
    bool checkValidString(string s) {
        // time: O(n), space: O(1)
        int leftMin = 0, leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                leftMin++; leftMax++;
            } else if (c == ')') {
                leftMin--; leftMax--;
            } else {
                leftMin--; leftMax++;
            }
            if (leftMax < 0) return false; // 即便把所有的 * 都当 '(' 用，也抵消不了那么多右括号
            if (leftMin < 0) leftMin = 0; // 代表可以用 * 来当做 ( 来抵消 )
        }
        return leftMin == 0; // 剩余 ( 并且无法用 * 来抵消
    }
};
