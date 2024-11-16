/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 2 || x == 3) return 1;
        if(x == 4) return 2;
        long left = 1, right = min(x, 46340);
        while(left <= right){
            int mid = left + (right - left) / 2;
            //cout << left << ' ' << right << " " << mid << endl;
            if(mid * mid <= x){ // 如果不确定的话，可以手算几个实例试试
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end

