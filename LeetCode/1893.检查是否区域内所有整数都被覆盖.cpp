class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for(auto r : ranges){
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }

        vector<int> arr;
        arr.push_back(diff[0]);
        int sum = diff[0];
        for(int i = 1; i < 51; ++i){
            sum += diff[i];
            arr.push_back(sum);
        }

        for(int i = left; i <= right; ++i){
            if(arr[i] <= 0) return false; 
        }

        return 1;
    }
};