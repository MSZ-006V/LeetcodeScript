class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // tc O(n*m), sc O(1)
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        res.reserve(n * m);
        for(int k = 0; k < m + n - 1; ++k){
            int min_j = max(k - m + 1, 0);
            int max_j = min(n - 1, k);
            if(k % 2 == 0){
                for(int j = min_j; j <= max_j; ++j){
                    res.push_back(mat[k - j][j]);
                }
            }
            else{
                for(int j = max_j; j >= min_j; --j){
                    res.push_back(mat[k - j][j]);
                }
            }
        }

        return res;
    }
};