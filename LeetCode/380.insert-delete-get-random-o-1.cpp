/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
private:
    unordered_map<int, int> ht;
    vector<int> nums;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(ht.find(val) == ht.end()){
            nums.push_back(val);
            ht[val] = nums.size() - 1;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(ht.find(val) == ht.end()){
            return false;
        }
        else{
            // 删除元素O(1)的做法就是将当前要删除的元素与最后一个元素交换
            // 然后再从ht中删除，数组弹出最后一个元素，更新最后一个元素在ht中下标即可
            nums[ht[val]] = nums[nums.size() - 1];
            nums.pop_back();
            ht[nums[ht[val]]] = ht[val];
            ht.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return nums[(rand() % (nums.size()))];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

