

//17. 电话号码的字母组合

// 分析：画树型图分析
// 分析：宽 和 高 是由谁来决定的
// 技巧：可以把回溯过程写在参数里

#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    vector<string> res;
    string path;

    // 也可以用hash表
    vector<string> map ={"","" ,"abc","def",
                         "ghi","jkl","mno",
                         "pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        backtracking(digits,0);
        return res;
    }

    // idex 表示 digits的第几个元素
    void backtracking(string digits, int index){
        if(path.size()==digits.size()){
            res.push_back(path);
            return;
        }
        int digit = digits[index]-'0';
        for(int i=0;i<map[digit].size();i++){
            path.push_back(map[digit][i]);
            backtracking(digits, index+1);  // 注意个之前 startindex的区别
            path.pop_back();
        }
    }

    //void backtracking(string digits, int startindx){
    //    if(path.size()==digits.size()){
    //        res.push_back(path);
    //        return;
    //    }
    //
    //    for(int i =startindx;i<digits.size();++i){
    //        char c = digits[i];
    //        int t = c-'0';
    //        for(int j=0;map[t].size();j++){
    //            path.push_back(map[t][j]);
    //            backtracking(digits,i+1);
    //            path.pop_back();
    //        }
    //    }
    //}
};