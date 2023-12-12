

//79. 单词搜索
// 思路写出来了，但是斜街不对

/**
 * 1,防止重复遍历
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> used(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == word[0]){
                    used[i][j]=1;
                    if(backtracking(board,used,word,i,j,1)){
                        return true;
                    }
                    used[i][j]=0;
                }
            }
        }
        return false;
    }

    bool
    backtracking(vector<vector<char>> &board, vector<vector<int>> &used, string word, int row, int col, int index) {
        if (index >= word.size()) {
            return true;
        }
        bool r1, r2, r3, r4;
        r1 = r2 = r3 = r4 = false;
        //上
        if (row - 1 >= 0 && used[row - 1][col] == 0 && board[row - 1][col] == word[index]) {
            used[row - 1][col] = 1;
            r1 = backtracking(board, used, word, row - 1, col, index + 1);
            used[row - 1][col] = 0;
        }
        //下
        if (row + 1 < board.size() && used[row + 1][col] == 0 && board[row + 1][col] == word[index]) {
            used[row + 1][col] = 1;
            r2 = backtracking(board, used, word, row + 1, col, index + 1);
            used[row + 1][col] = 0;
        }
        //左
        if (col - 1 >= 0 && used[row][col - 1] == 0 && board[row][col - 1] == word[index]) {
            used[row][col - 1] = 1;
            r3 = backtracking(board, used, word, row, col - 1, index + 1);
            used[row][col - 1] = 0;
        }
        //右
        if (col + 1 < board[0].size() && used[row][col + 1] == 0 && board[row][col + 1] == word[index]) {
            used[row][col + 1] = 1;
            r4 = backtracking(board, used, word, row, col + 1, index + 1);
            used[row][col + 1] = 0;
        }
        return r1 && r2 && r3 && r4;
    }
};

// 和我的思路一致
class Solution_2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if (dfs(board, visited, word, 0, i, j)) return true;
            }
        }

        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int str_idx, int i, int j) {
        if (str_idx == word.size()) return true;
        // 越界、被访问过、当前位置的字符不是word对应位置的字符
        if (i >= board.size() || i < 0 ||
            j >= board[0].size() || j < 0 ||
            visited[i][j] == true || board[i][j] != word[str_idx]) return false;

        visited[i][j] = true;
        if (dfs(board, visited, word, str_idx + 1, i + 1, j) ||
            dfs(board, visited, word, str_idx + 1, i - 1, j) ||
            dfs(board, visited, word, str_idx + 1, i, j + 1) ||
            dfs(board, visited, word, str_idx + 1, i, j - 1)) return true;
        visited[i][j] = false;

        return false;

    }
};
//
//作者：喜刷刷
//        链接：https://leetcode.cn/problems/word-search/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution_1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
        if (k == word.size() - 1) return true;
        board[i][j] = '\0';
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
        board[i][j] = word[k];
        return res;
    }
};

//作者：Krahets
//        链接：https://leetcode.cn/problems/word-search/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。