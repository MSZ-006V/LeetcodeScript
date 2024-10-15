/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
// 也是有点复杂难懂题意，但是整体思路不难，和981基于时间的键值存储思路类似
// 都是在一个数组里面（每个元素是一个二元组），基于二元组的第一个或第二个元素
// 查找大于或者大于等于的数，然后返回前一个，这里是找最大的一个，所以用upper_bound, 然后返回前一个
private:
    int snap_cnt;
    vector<vector<pair<int, int>>> ht;
public:
    SnapshotArray(int length): snap_cnt(0), ht(length) {
        
    }
    
    void set(int index, int val) {
        ht[index].push_back({snap_cnt, val});
    }
    
    int snap() {
        return snap_cnt++;
    }
    
    int get(int index, int snap_id) {
        auto x = ranges::upper_bound(ht[index].begin(), ht[index].end(), pair{snap_id + 1, -1});
        return x == ht[index].begin()?0:(x - 1)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

