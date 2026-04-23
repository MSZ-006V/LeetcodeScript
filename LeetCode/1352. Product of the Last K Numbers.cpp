class ProductOfNumbers {
public:
// 如果没有 0 的话，直接考虑维护一个前缀积 pre[i] 表示前 i 个数的乘积即可，答案就是 pre[n−k] / pre[n]
// 其中 n 表示当前 pre 数组的长度。那么如何处理 0 呢？可以注意到如果出现 0 的话，那么 0 之前的数对答案都是没有用的了，所以我们可以遇到 0 的时候直接清空 pre 数组，
// 那么询问的时候我们要求的是末尾 k 个数的乘积，如果这时候我们 pre 数组的长度小于 k，说明末尾 k 个数里肯定有 0，直接输出 0 即可，否则输出 pre[n−k] / pre[n]
    int len;
    vector<int> pre;
    ProductOfNumbers() {
        pre = vector<int>(40010, 0);
        pre[0] = 1;
        len = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            len = 0;
        }
        else {
            len++;
            pre[len] = num;
            pre[len] *= pre[len - 1];
        }
    }
    
    int getProduct(int k) {
        if (len < k) return 0;
        return pre[len] / pre[len - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */