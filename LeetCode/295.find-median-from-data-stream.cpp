/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
private:
    // 用两个优先队列进行模拟
    // left_pq - right_pq
    // 小 -> 大  小 -> 大
    // 所以左边的队头是最大元素，用大根堆，右边的队头是最小的元素，用小根堆
    // 当两个队列长度相等说明数组长度是偶数，否则是奇数（设定left比right多一个）
    // 按照不同的情况返回不同的计算结果

    // 同时，按照两个不同长度的队列，对插入的元素进行不同的处理
    priority_queue<int, vector<int>, greater<>> right_heap; // 最小堆，用作数组右边
    priority_queue<int> left_heap; // 最大堆，用作数组左边
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        int len_left = left_heap.size(), len_right = right_heap.size();
        if(len_left == len_right){
            if(len_left == 0){
                left_heap.push(num);
            }
            else if(num > right_heap.top()){
                left_heap.push(right_heap.top()); right_heap.pop();
                right_heap.push(num);
            }
            else{
                left_heap.push(num);
            }
        }
        else{
            if(num > left_heap.top()){
                right_heap.push(num);
            }
            else{
                right_heap.push(left_heap.top()); left_heap.pop();
                left_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        int len_left = left_heap.size(), len_right = right_heap.size();
        if(len_left == len_right){
            return (left_heap.top() + right_heap.top()) / double(2);
        }
        else{
            return left_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

