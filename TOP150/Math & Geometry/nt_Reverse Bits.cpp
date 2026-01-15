class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t res = 0;
        for(int i = 0; i < 32; ++i){
            uint64_t bit = (n >> i) & 1;
            res |= bit << (31 - i);
        }
        return res;
    }
};
