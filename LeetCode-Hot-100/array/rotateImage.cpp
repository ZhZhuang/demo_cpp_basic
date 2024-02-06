//
// Created by Administrator on 2024/1/10.
//
//48. 旋转图像
// 原地顺时针旋转90度

// 分析：仔细找规律得出 （i,j） -->(j,n-i+1), 没什么用
// 分析2：发现沿着主对角线反转，沿着中心竖线反转，成了

#include <vector>
using namespace std;

class Solution {
public:
    // matrix 是方的
    void rotate(vector<vector<int>>& matrix) {
        //主对角线反转
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //沿着中心竖线反转
        for(int i=0;i<matrix.size();i++){
            for(int j=0,k=matrix.size()-1;j<k;j++,k--)
                swap(matrix[i][j],matrix[i][k]);
        }
    }
};

// 借助辅助矩阵
class Solution_2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 深拷贝 matrix -> tmp
        vector<vector<int>> tmp = matrix;
        // 根据元素旋转公式，遍历修改原矩阵 matrix 的各元素
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[j][n - 1 - i] = tmp[i][j];
            }
        }
    }
};
//
//作者：Krahets
//        链接：https://leetcode.cn/problems/rotate-image/solutions/1228078/48-xuan-zhuan-tu-xiang-fu-zhu-ju-zhen-yu-jobi/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。