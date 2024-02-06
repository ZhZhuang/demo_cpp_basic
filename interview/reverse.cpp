//
// Created by Administrator on 2024/1/25.
//

//题目是一种反转字符串，比如”www.kuaishou.com“变成”com.kuaishou.www“


// 思路一：分割

// 思路二：更通用的思路是先反转全部字符，然后再反转每个.中间的字符即可。

//#include <string>
//using namespace std;
//
//void help(string &s, int start, int end){
//    for(int i=start,j=end;i<j;i++,j--){
//        swap(s[i],s[j]);
//    }
//}
//
//void reverse(string s){
//    help(s,0,s.size()-1);
//    int start = 0,end = 0;
//    for(int i=0;i<s.size();i++){
//        if(s[i] == '.'){
//
//        }
//    }
//}

//========================================

#include <iostream>
#include <algorithm>

void reverseString(std::string& str, int start, int end) {
    while (start < end) {
        std::swap(str[start], str[end]);
        start++;
        end--;
    }
}

void reverseWords(std::string& str) {
    int start = 0;
    int end = str.length() - 1;

    // 反转整个字符串
    reverseString(str, start, end);

    // 反转每个单词内部的字符
    start = 0;
    for (int i = 0; i <= end; ++i) {
        if (str[i] == '.') {
            reverseString(str, start, i - 1);
            start = i + 1;
        }
    }

    // 反转最后一个单词内部的字符
    reverseString(str, start, end);
}

int main() {
    std::string original = "www.kuaishou.com";

    std::cout << "Original String: " << original << std::endl;

    // 调用反转函数
    reverseWords(original);

    std::cout << "Reversed String: " << original << std::endl;

    return 0;
}
