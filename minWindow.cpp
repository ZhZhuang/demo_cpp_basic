//
// Created by Administrator on 2023/11/27.
//


// 思路：哈希表 + 滑动窗口

// 区间：[left, right)
// 滑动窗口的一般逻辑
/*    int left = 0, right = 0; // 初始化左右边界

    while (right < s.size()) {`
        // 增大窗口
        window.add(s[right]);
        right++; //移动右边界

        while (符合要求) {
            // 缩小窗口
            window.remove(s[left]);
            left++; //移动左边界
            }
    }*/
//————————————————
//版权声明：本文为CSDN博主「zj134_」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/qq_32523711/article/details/107578714

#include <string>
#include <unordered_map>
using namespace std;

bool  compare( unordered_map<char, int> tmap, unordered_map<char, int> map){
    return false;
}

string minWindow(string s, string t) {
    unordered_map<char, int> map;
    unordered_map<char, int> tmap;
    int left, right;
    int min=INT_MAX;
    // 初始化目标
    for(char c: t){
        map[c]++;
    }
    //for(left=0,right=0;left<s.size();left++){
    while (left<s.size()){
        if(right-left<t.size() && right<s.size()){
            tmap[s[right]]++;
            right++;
        }
        if(compare(tmap,map)){
            min = min< right-left ? min : right-left;
            tmap[s[left]]--;
            left++;
        }
    }
}

// 参考
string minWindow_1(string s, string t) {
    unordered_map<char, int> hs, ht;
    for (auto c: t) ht[c] ++ ;
    string res;
    int cnt = ;
    for (int i = 0, j = 0; i < s.size(); i ++ ) {
        hs[s[i]] ++ ;
        if (hs[s[i]] <= ht[s[i]]) cnt ++ ;

        while (hs[s[j]] > ht[s[j]])
            hs[s[j ++ ]] -- ;
        if (cnt == t.size()) {
            if (res.empty() || i - j + 1 < res.size())
                res = s.substr(j, i - j + 1);
        }
    }
    return res;
}

//作者：林小鹿
//        链接：https://leetcode.cn/problems/minimum-window-substring/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。