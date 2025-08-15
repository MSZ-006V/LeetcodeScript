#include <iostream>
#include <vector>

using namespace std;

int main() {
    ListNode* dh = new ListNode()
}

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(target <= nums[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

vector<vector<int>> results;
queue<TreeNode*> que;
que.push(root);

while(!que.empty()){
    int size = que.size();
    vector<int> level;
    for(int i = 0; i < size; ++i){
        TreeNode* cur = que.front(); que.pop();
        level.push_back(cur->val);
        if(cur->left) que.push(cur)
    }
}