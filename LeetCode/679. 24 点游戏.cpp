class Solution {
public:
    // 每次从数组中任选两个数进行运算，合成一个新的数，放回数组，直到数组只剩下一个数，判断这个数是否等于 24。
    const double EPS = 1e-9;

    // 其实这个做法不难，只是思路比较难想
    bool dfs(vector<double>& cards){
        if(cards.size() == 1){
            return abs(cards[0] - 24) < EPS;
        }

        int n = cards.size();
        for(int i = 0; i < n; ++i){
            double x = cards[i];
            for(int j = i + 1; j < n; ++j){
                double y = cards[j];

                vector<double> candi = {x + y, x - y, y - x, x * y}; // 4种
                if(abs(y) > EPS){
                    candi.push_back(x / y); // 如果abs(y) > EPS, 则代表y不为0
                }
                if(abs(x) > EPS){
                    candi.push_back(y / x);
                }

                vector<double> newc = cards;
                newc.erase(newc.begin() + j);
                for(auto c : candi){
                    newc[i] = c;
                    if(dfs(newc)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> a(cards.begin(), cards.end());
        return dfs(a);
    }
};
// 时间复杂度：虽然看起来递归很多，但对于 4 张牌来说，规模极小。
// 第一层选两个数有 $C_4^2 = 6$ 种，运算有 6 种；
// 第二层选两个数有 $C_3^2 = 3$ 种，运算有 6 种；
// 第三层选两个数有 $C_2^2 = 1$ 种，运算有 6 种；
// 总状态数约为 $9216$ 种，对于计算机来说是瞬间完成。
// 空间复杂度：$O(1)$ 或 $O(N)$。递归深度恒定为 4 层，每次创建新数组，开销非常小。