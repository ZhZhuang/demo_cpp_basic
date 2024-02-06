//
// Created by Administrator on 2024/1/10.
//

//73. 矩阵置零

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool> use1(row),use2(col);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    use1[i] =true;
                    use2[j] = true;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) {
                if(use1[i] || use2[j])
                    matrix[i][j]=0;
            }
        }

    }
};