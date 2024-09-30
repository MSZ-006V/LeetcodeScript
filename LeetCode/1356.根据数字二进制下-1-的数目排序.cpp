/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
public:
    static int bitCount(int n){
        int count = 0;
        while(n){
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    static bool cmp(int a, int b){
        int bita = bitCount(a);
        int bitb = bitCount(b);
        if(bita == bitb)
            return a < b;
        else
            return bita < bitb;
    }
    vector<int> sortByBits(vector<int>& arr) {
    // 主要考察如何计算一个数中1的个数
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
// @lc code=end

