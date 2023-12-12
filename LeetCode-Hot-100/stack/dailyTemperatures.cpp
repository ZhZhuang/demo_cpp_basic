
//  有点意思
// 倒序，索引数组

#include <climits>      // INT_MAX
#include <vector>
using namespace std;

class Solution {
public:
    // 枚举
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //vector<int> *res = new vector<int>(temperatures.size());
        vector<int> res(temperatures.size());
        int len = temperatures.size();
        for(int i=0;i < len-1;i++){
            int temp =0;
            for(int j=i+1;j<len;j++){
                ++temp;
                if(temperatures[i]<temperatures[j]){
                    res[i]=temp;
                    break;
                }
            }
        }
        return res;
    }
};


// 官方
class Solution_1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n), next(101, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {  // 倒序
            int warmerIndex = INT_MAX;
            for (int t = temperatures[i] + 1; t <= 100; ++t) {
                warmerIndex = min(warmerIndex, next[t]);
            }
            if (warmerIndex != INT_MAX) {
                ans[i] = warmerIndex - i;
            }
            next[temperatures[i]] = i;
        }
        return ans;
    }
};
