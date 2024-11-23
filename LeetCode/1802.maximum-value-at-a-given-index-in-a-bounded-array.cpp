/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution {
public:
    bool check(int n, int index, int maxSum, int val){
        // 计算左边区间的和，最大的左边区间可以被描述为1,..., 1, 2, 3,..., index - 2, index - 1
        int left = index; 
        // 计算右边区间的和，最大的右边区间可以被描述为index - 1, index - 2,..., 2, 1, 1,..., 1
        int right = n - index - 1; 
        // 根据数组长度n和当前val的下标index可以分别计算出这两个区间的和，从而进行判断，为了防止数据溢出要使用long类型
        return val + cal(val, left) + cal(val, right) <= maxSum;
    }

    // 这个计算方法用了高斯的方法
    // 因为区间可以被描述为上面的那种形式，而左右两个区间的长度是可以计算出来的
    // 根据是否会有一连串的1的情况，做一个if，如果有就加上ones，没有就计算前半部分就行
    // 思想比较巧妙，原理很简单，代码实现需要小心谨慎防止下标错误
    long cal(int val, int length){
        // 先使用1进行填充，剩下的多的，逐渐递增直到达到val的值
        if (length + 1 < val) {
            int small = val - length;
            return (long) (val - 1 + small) * length / 2;
        } else {
            int ones = length - (val - 1);
            return (long) val * (val - 1) / 2 + ones;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        // 使用二分查找加检查区间是否合法的方法
        int left = 1, right = maxSum;
        int ans = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(n, index, maxSum, mid)){
                left = mid + 1;
                ans = mid;
            }
            else{
                right = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end

