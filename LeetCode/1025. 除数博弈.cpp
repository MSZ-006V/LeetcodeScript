class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};

// 没有头绪的时候，可以尝试的写出博弈问题的前几个步骤
// 然后进行分析，比如这一道题，写出几步后就能发现，当n为偶数时，Alice总能赢，当n为奇数时，Bob总能赢
// 以此进行分析推论