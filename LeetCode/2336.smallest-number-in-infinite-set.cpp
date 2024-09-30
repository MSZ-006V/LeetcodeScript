/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, std::greater<int>> pq; // 最小堆
    unordered_set<int> numset; // 记录队列中的元素，用来判断是否可以插入
    int max = 0; // 记录最大的数，因为pq设置的是最小堆，最小的元素排在最前面
    // 不能访问到队列最末尾的元素，所以用一个max来记录
public:
    SmallestInfiniteSet() {
        max = 1;
        pq.push(1);
        numset.insert(1);
    }
    
    int popSmallest() {
        int x = pq.top(); pq.pop();
        numset.erase(x);

        if(pq.empty()){
            pq.push(x + 1);
            numset.insert(x + 1);
            max = x + 1;
        } 

        return x;
    }
    
    void addBack(int num) {
        if(num < max && numset.find(num) == numset.end()){
            pq.push(num);
            numset.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

