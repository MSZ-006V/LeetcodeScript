class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> ht;
        for(auto num : hand){
            ht[num]++;
        }

        for(auto& [val, freq] : ht){
            if(freq > 0){
                int take = freq;
                for(int i = 0; i < groupSize; ++i){
                    if(ht[val + i] < take) return false;
                    ht[val + i] -= take;
                }
            }
        }

        return true;
    }
};
