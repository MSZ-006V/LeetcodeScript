/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        // time complexity is O(n), space complexity is O(n)
        // 把所有球转移到当前下标为 i 的盒子的操作数为operation，初始情况下当前盒子
        // 及其左侧有left个球，右侧有right个球。那么，已知这三者的情况下，
        // 把所有球转移到当前下标为 i+1 的盒子的操作数就是operation + left - right
        // 同时如果遇到当前盒子是1，就调整left和right的值

        int left = boxes[0] - '0', right = 0, operations = 0;
        int n = boxes.size();
        for(int i = 1; i < n; ++i){
            if(boxes[i] == '1'){
                right++;
                operations += i;
            }
        }

        vector<int> result;
        result.push_back(operations);
        for(int i = 1; i < n; ++i){
            operations += left - right;
            if(boxes[i] == '1'){
                left++;
                right--;
            }
            result.push_back(operations);
        }

        return result;

        // time complexity is O(n^2)
        int n = boxes.size();
        vector<int> pos;
        for(int i = 0; i < n; ++i){
            if(boxes[i] == '1'){
                pos.push_back(i);
            }
        }

        vector<int> result;
        for(int i = 0; i < n; ++i){
            int res = 0;
            for(auto p : pos){
                res += abs(p - i);
            }
            result.push_back(res);
        }

        return result;
    }
};
// @lc code=end

