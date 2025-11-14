class Solution {
public:
    // 上右下左
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    set<pair<int,int>> visited;

    void goBack(Robot &robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void dfs(Robot &robot, int x, int y, int d) {
        robot.clean();
        visited.insert({x, y});

        for (int i = 0; i < 4; ++i) {
            int nd = (d + i) % 4;
            int nx = x + dirs[nd][0];
            int ny = y + dirs[nd][1];

            if (!visited.count({nx, ny}) && robot.move()) {
                dfs(robot, nx, ny, nd);
                goBack(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};
