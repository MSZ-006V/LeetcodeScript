class Solution {
public:
    bool isHappy(int n) {
        // tc: O(log n), sc: O(log n)
        unordered_set<int> sets;
        while(n != 1){ // 不管你初始 n 多大, 经过一次“平方和”变换后，n 会迅速变小
            sets.insert(n);

            int new_n = 0;
            while(n != 0){ // 内层循环计算的时间复杂度是 O(log n)
                int digit = n % 10;
                n = n / 10;
                new_n += digit * digit;
            }
            n = new_n;
            if(sets.find(new_n) != sets.end()) return false;
        }

        return true;
    }
};

// 或者也可以使用快慢指针（参考链表环检测）
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = sumOfSquares(n);

        while (slow != fast) {
            fast = sumOfSquares(fast); // 每次走两步
            fast = sumOfSquares(fast);
            slow = sumOfSquares(slow); // 每次走一步
        }

        return fast == 1;
    }

private:
    int sumOfSquares(int n) {
        int output = 0;
        while (n != 0) {
            output += (n % 10) * (n % 10);
            n /= 10;
        }
        return output;
    }
};