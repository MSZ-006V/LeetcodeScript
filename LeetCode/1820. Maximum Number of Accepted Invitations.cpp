class Solution {
 public:
  int maximumInvitations(const vector<vector<int>>& grid) {
    int m = grid.size();    // Boys 数量
    int n = grid[0].size(); // Girls 数量
    
    // match_girl[j] = i 表示第 j 个女孩目前被第 i 个男孩匹配了
    // 初始化为 -1 表示所有女孩目前都是单身
    vector<int> match_girl(n, -1);
    int max_matches = 0;

    for (int i = 0; i < m; ++i) {
      // 每次尝试为一个新男孩找匹配时，都要重置“已访问女孩”列表
      vector<bool> visited_girls(n, false);
      if (Dfs(i, grid, visited_girls, match_girl)) {
        max_matches++;
      }
    }

    return max_matches;
  }

 private:
  bool Dfs(int boy_id, const vector<vector<int>>& grid, 
           vector<bool>& visited_girls, vector<int>& match_girl) {
    int num_girls = grid[0].size();

    for (int j = 0; j < num_girls; ++j) {
      // 如果这个男孩喜欢这个女孩，且在这个“协商回合”中该女孩还没被问过
      if (grid[boy_id][j] == 1 && !visited_girls[j]) {
        visited_girls[j] = true; // 标记该女孩在本轮已被“求婚”

        // 核心逻辑：
        // 1. 如果女孩单身
        // 2. 或者虽然她有男友，但她的男友可以“腾挪”去选别的女孩
        if (match_girl[j] == -1 || Dfs(match_girl[j], grid, visited_girls, match_girl)) {
          match_girl[j] = boy_id; // 匹配成功
          return true;
        }
      }
    }
    return false;
  }
};