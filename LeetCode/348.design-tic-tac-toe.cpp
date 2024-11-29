/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
// 这道题很难，主要是想不出来这个做法，不然很简单的
// 具体的做法看代码看不太出来，可以拿去问GPT解释代码
// 简略的解释就是，rowjudge数组记录每一行的个数，另一个记录每一列的个数
// 两个玩家的操作值分别是1和-1，diag代表正对角线，anti_diag代表反对角线
// 因为棋盘是n*n的，当玩家想在对角线下赢的时候，只能下在正对角线或者是反对角线，不然不可能赢，所以其他的对角线不用考虑
// 比如假设棋盘3*3，在第一行，1号玩家下了2步，2号玩家下了1步，那么这行的个数就是1,永远不可能有人在这里赢了
// 假如第2行，1号玩家下了3步，那就赢了，所以就是通过+1，-1的不断操作，然后判断就可以了
// 注意rowjudge和coljudge的每一个下标，代表的都是每一行每一列的总分数
class TicTacToe {
private:
    vector<int> rowjudge;
    vector<int> coljudge;
    int diag, anti_diag;
    int total;
    int num;
public:
    TicTacToe(int n): total(n), diag(0), anti_diag(0), rowjudge(n), coljudge(n), num(n) {
        
    }
    
    int move(int row, int col, int player) {
        int add = player == 1?1:-1;
        diag = diag + (row == col?add:0);
        anti_diag = anti_diag + (row == (num - col - 1)?add:0);
        rowjudge[row] += add;
        coljudge[col] += add;

        if(abs(diag) == total || abs(anti_diag) == total || abs(rowjudge[row]) == total || abs(coljudge[col]) == total){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
// @lc code=end

