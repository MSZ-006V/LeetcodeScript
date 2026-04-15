class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0); // 初始全部为无色（0）
        vector<int> res;
        int count = 0; // 当前相邻同色对的数量

        for (auto& q : queries) {
            int idx = q[0];
            int color = q[1];

            // --- 1. 修改前：减去被破坏的贡献 ---
            // 只有当前位置有颜色时，才可能对 count 有贡献
            if (nums[idx] != 0) {
                // 检查左边
                if (idx > 0 && nums[idx] == nums[idx - 1]) {
                    count--;
                }
                // 检查右边
                if (idx < n - 1 && nums[idx] == nums[idx + 1]) {
                    count--;
                }
            }

            // --- 2. 执行修改 ---
            nums[idx] = color;

            // --- 3. 修改后：加上新产生的贡献 ---
            // 检查左边
            if (idx > 0 && nums[idx] == nums[idx - 1]) {
                count++;
            }
            // 检查右边
            if (idx < n - 1 && nums[idx] == nums[idx + 1]) {
                count++;
            }

            res.push_back(count);
        }

        return res;
    }
};