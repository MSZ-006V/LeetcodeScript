class Solution {
public:
    int queen_num;
    vector<vector<string>> result;
    bool place(int k, int j, vector<int>& a){
        if(j == 1) return true;
        for(int i = 1; i < j; ++i){
            if(a[i] == k) return false;
            if(abs(i - j) == abs(a[i] - k)) return false;
        }
        return true;
    }

    void find(int j, vector<int>& a){
        if(j == queen_num + 1){
            vector<string> map(queen_num, string(queen_num, '.'));
            for(int i = 1; i < queen_num + 1; ++i){
                map[i - 1][a[i] - 1] = 'Q';
            }
            result.push_back(map);
        }

        for(int k = 1; k < queen_num + 1; ++k){
            if(place(k, j, a)){
                a[j] = k;
                find(j + 1, a);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        queen_num = n;
        vector<int> a(n + 1, 0);
        find(1, a);
        return result;
    }
};
