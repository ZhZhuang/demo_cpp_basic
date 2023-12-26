

// 118. 杨辉三角

// 参考官方代码，写的比较简洁

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> dp(1,1);
        vector<vector<int>> res;
        for(int i=1;i<=numRows;i++){
            vector<int> temp(i,1);
            for(int j=1;j<i-1;j++){
                temp[j]=dp[j]+dp[j-1];
            }
            res.push_back(temp);
            dp = temp;
        }
        return res;
    }
};

// 官方
class Solution_1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
//
//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/pascals-triangle/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。