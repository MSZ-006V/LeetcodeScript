class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // tc: O(n), sc: O(n)
        vector<vector<int>> tris;
        for(auto tri : triplets){
            if(tri[0] <= target[0] && tri[1] <= target[1] && tri[2] <= target[2]){
                tris.push_back(tri);
            }
        }

        bool one = false, second = false, third = false;
        for(auto tri : tris){
            if(tri[0] == target[0]) one = true;
            if(tri[1] == target[1]) second = true;
            if(tri[2] == target[2]) third = true;
        }

        return one && second && third;
    }
};
