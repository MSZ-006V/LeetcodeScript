class Solution {
public:
    int countTime(vector<int>& piles, int rate){
        int time = 0;
        for(auto& pile : piles){
            time += (pile - 1) / rate + 1;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // tc O(logn), sc O(1)

        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(countTime(piles, mid) <= h){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
};
