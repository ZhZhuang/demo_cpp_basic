
//93. 复原 IP 地址
//  回溯 + 分割
// 注意：先做分割回文


// 思路：想不出好的先暴力

//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]

// 公司：华为，字节，携程，美团，特斯拉笔试
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

    }

    void backtracking(){

    }
};


class Solution_ {
public:
    vector<string> restoreIpAddresses(string s) {
        string temp;
        vector<string> res;
        int len = s.size();
        for(int i=1;i<len-3;++i){
            string s1 = s.substr(0,i);
            for(int j=i;j<len-2;++j){

                for(int k=j;k<len-1;k++){

                }
            }
        }
    }
};