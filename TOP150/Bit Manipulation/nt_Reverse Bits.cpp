class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t res = 0;
        for(int i = 0; i < 32; ++i){
            uint64_t bit = (n >> i) & 1;    // 提取数字 n 的第i位
            res |= bit << (31 - i);         // 将提取的位放到结果的相应位置
        }
        return res;
    }
};
