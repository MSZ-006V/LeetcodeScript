class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

        int node_num = matrix.size() * matrix[0].size();
        vector<int> result(node_num);

        int x = 0, y = 0;
        int direction = 0;

        for(int i = 0; i < node_num; ++i){
            visited[x][y] = true;
            result[i] = matrix[x][y];
            int nx = x + dir[direction][0];
            int ny = y + dir[direction][1];

            if(nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size() || visited[nx][ny]){
                direction = (direction + 1) % 4;
            }
            x += dir[direction][0];
            y += dir[direction][1];
        }
        return result;
    }
};
