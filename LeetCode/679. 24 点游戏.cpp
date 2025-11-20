class Solution {
public:
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