class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[y][x]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        if(!cnt.count(y)) return 0;

        unordered_map<int, int>& ycnt = cnt[y];
        for(auto &[col, colcnt] : cnt){
            if(col != y){
                int d = col - y;
                res += (colcnt.count(x) ? colcnt[x] : 0) * (ycnt.count(x + d) ? ycnt[x + d] : 0) * 
                       (colcnt.count(x + d)? colcnt[x + d] : 0);
                res += (colcnt.count(x) ? colcnt[x] : 0) * (ycnt.count(x - d) ? ycnt[x - d] : 0) * 
                       (colcnt.count(x - d) ? colcnt[x - d] : 0);
            }
        }

        return res;
    }
};
