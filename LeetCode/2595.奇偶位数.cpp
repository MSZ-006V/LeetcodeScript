/*
 * @lc app=leetcode.cn id=2595 lang=cpp
 *
 * [2595] 奇偶位数
 */

// @lc code=start
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd = 0;
        int even = 0;
        int index = 0;
        while(n > 0){
            if(n % 2 == 1 && index % 2 == 0) even++;
            else if(n % 2 == 1 && index % 2 == 1) odd++;
            n = n / 2;
            index++;
            //cout << n << ' ' << index << endl;
        }
        //cout << odd << ' ' << even;
        return {even, odd};
    }
};
// @lc code=end

