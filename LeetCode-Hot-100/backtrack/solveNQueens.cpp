
// 思路：先想for循环

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n,string(n,'.'));
        backtracking(chessboard,n,0);
        return res;
    }

    void backtracking(vector<string> &chessboard,int n, int row){
        if(row>=n){
            res.push_back(chessboard);
            return;
        }
        for(int i= 0;i<n;i++){  // 第 row 行， 第 i 列
            if(check(chessboard,n,row,i)){  //尝试 第 row 行， 第 i 列 放置Q是否合适
                chessboard[row][i] = 'Q';
                backtracking(chessboard,n,row+1);
                chessboard[row][i] = '.';
            }
        }
    }

    bool check(vector<string> &chessboard,int n,int row,int col){
        // 检查列
        for(int i=0;i<row;i++){
            if(chessboard[i][col] == 'Q')
                return false;
        }
        // 45度
        for(int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--){
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
