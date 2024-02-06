//牛客网 [编程题]01背包
//https://www.nowcoder.com/questionTerminal/e1bc39c4f2004be3b192f343dac198cd

// 视频教程
// https://www.bilibili.com/video/BV1BU4y177kY/?spm_id_from=333.788&vd_source=f48666313e287bbf423762465f29de45

// 0-1 背包问题

// 要求：熟练掌握代码，深入理解01背包问题

// 方法一：暴力回溯
// 方法二：动态规划

/***********************  二维dp数组  **********************************/
//dp[i][j]的含义：0到i的物品任取，放到容量为j的背包，dp[i][j]为最大价值

//对于dp[i][j]
// 不放物品i，dp[i-1][j]
// 放置物品i，dp[i-1][j-w[i]] + value[i]
// 故，dp[i][j] = max(
            //        dp[i-1][j],                 // 不放物品i
            //        dp[i-1][j-w[i]] + value[i]  // 放置物品i
//                   )

/***********************  一维dp数组（滚动数组） **********************************/
//dp[j]的含义：背包容量为j的最大价值
// dp[j]= max(dp[j], dp[j-w[i]] + value[i)
// 解释：参考二维dp数组进行理解
// 遍历顺序，先遍历物品在遍历背包，也就是，以行为单位进行遍历
// 而且遍历背包容龄时必须要，从后往前遍历，因为如果从前往后遍历，dp[j]的值会被覆盖

/**
 * 思考：
 * 1，为什么二维的dp数组遍历顺序可以交换，也就是可以先遍历物品还或是遍历背包？
 * 2，为什么二维数组不需要倒序遍历，而一维滚动数组必须要倒序遍历？
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 二维动态数组
int main_1() {
    int v, n; // 最大体积和物品个数
    while (cin >> v >> n) { // 注意 while 处理多个 case
        vector<int> volume(n, 0);
        vector<int> weight(n, 0);
        int vol, weg;
        for(int i = 0; i < n; i++){
            cin >> vol >> weg;
            volume[i] = vol;
            weight[i] = weg;
        }

        vector<vector<int>> dp(n, vector<int>(v+1, 0));
        //初始化
        for(int j = volume[0]; j < v + 1; j++){ // 初始化物品重量大于等于背包的项
            dp[0][j] = weight[0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < v + 1; j++){
                //判断下标防止越界
                if(j >= volume[i])
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-volume[i]]+weight[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        printf("%d\n", dp[n-1][v]);
    }
    return 0;
}
 //64 位输出请用 printf("%lld")


 // 重点掌握
// 一维滚动数组
class Soulution_2{
public:
    int maxValue(vector<int> &w, vector<int> &v, int m){
        int n = w.size();
        vector<int> dp(m+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = m; j >= w[i]; j--) {    // 倒序更新
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
            print(dp);
        }
        return  dp[m];
    }

    int maxValue_error(vector<int> &w, vector<int> &v, int m){
        int n = w.size();
        vector<int> dp(m+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = w[i]; j <= m; j++) {    // 正序更新，变成了 完全背包问题
                dp[j] = max(dp[j],
                            dp[j - w[i]] + v[i]);
                // 等价于
                // dp[i][j] = max(dp[i-1][j],   //不放
                //                dp[i-1][j- w[i] + v[i]])  // 放
            }
            print(dp);
        }
        return  dp[m];
    }

    void print(vector<int> &dp){
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
};


// /////////////////////////////////////
//方法二：回溯法
// 回溯法解决 0-1 背包
class Soulution_3{
public:
    int maxvalue =0;
    int path = 0;
    void backtracking(vector<int> &w,vector<int> &v,
                      int index, int weight){
        if(index >= v.size()){  // 在叶子节点收割
            if(path > maxvalue)
                maxvalue= path;
            return;
        }
        if(weight>=w[index]){   // 背包可以放下当前物品
            path += v[index];
            backtracking( w, v, index+1,weight-w[index]);
            path -= v[index];
            backtracking( w, v, index+1,weight);
        } else{
            backtracking( w, v, index+1,weight);
        }
    }

    int maxValue(vector<int> &w, vector<int> &v, int m) {
        backtracking(w, v, 0, m);
        return maxvalue;
    }
};

int main() {
    //vector<int> weights ={3, 4, 5, 6} ;
    //vector<int> values = {2, 3, 4, 5};
    //int capacity = 5;       // 最大重量

    vector<int> weights = {1, 3, 4};
    vector<int> values = {15, 20, 30};
    int capacity = 4;

    //vector<int> weights = {1,10};
    //vector<int> values = {3, 4};
    //int capacity = 10;
    //backtracking(weights, values, 0, capacity);
    //cout << "The maximum value is: " << maxvalue << endl;

    Soulution_2 s2;
    int maxValue = s2.maxValue(weights, values, capacity);
    cout << "The maximum value is: " << maxValue << endl;

    int err = s2.maxValue_error(weights, values, capacity);
    cout<< "error :"<< err<<endl;
    return 0;
}
