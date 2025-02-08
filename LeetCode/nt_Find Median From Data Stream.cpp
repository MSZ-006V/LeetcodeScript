class MedianFinder {
    private:
        priority_queue<int> left_heap; // 大 -> 小
        priority_queue<int, vector<int>, std::greater<int>> right_heap; // 小 -> 大
    public:
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            // 整体插入的逻辑就是，把一个数组分成两个部分，左边部分从小到大，最靠近中间的数是左边部分最大的，所以左边用最大优先队列
            // 右边部分从小到大，最靠近中间的数是右边部分最小的，右边用最小优先队列

            // 插入逻辑：如果左边多了，或者数太大了，那么这个数肯定是右边的数，就移右边队列一个数到左边就行
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
    