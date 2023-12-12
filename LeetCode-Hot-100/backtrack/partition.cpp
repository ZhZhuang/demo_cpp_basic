
///131. 分割回文串

//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string>  path;

    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return res;
    }

    /**
     * startindex 在此处作为分割线
     */
    void backtracking(string &s, int startindex){
        if(startindex>=s.size()){   // 在叶节点收割结果
            res.push_back(path);
            return;
        }
        for(int i = startindex;i<s.size();i++){
            if(isplalindrome(s,startindex,i)){
                //path.push_back(s.substr(startindex,i+1));
                path.push_back(s.substr(startindex,i-startindex+1));    // 参数的含义

                backtracking(s,i+1);
                path.pop_back();
            }
        }
    }

    bool isplalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++, end--;
        }
        return true;
    }
};