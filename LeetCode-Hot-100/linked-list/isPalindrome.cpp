//
// Created by Administrator on 2023/11/25.
//


//234. 回文链表
// 注意：有改进的方法

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        ListNode *p = head;
        while (p!= nullptr){
            list.push_back(p->val);
            p = p->next;
        }
        for(int i =0, j = list.size()-1;i<j;i++,j--){
            if(list[i]!=list[j])
                return false;
        }
        return true;
    }
};


// 递归
//class Solution {
//public:
//    int ans=true;
//    ListNode* front;
//    void dfs(ListNode* tail)
//    {
//        if(!tail)return;
//        dfs(tail->next);
//
//        //回溯
//        if(ans)
//        {
//            if(tail->val!=front->val)
//                ans=false;
//            else front=front->next;
//        }
//    }
//    bool isPalindrome(ListNode* head)
//    {
//        front=head;
//        dfs(head);
//        return ans;
//    }
//};
//
//作者：单车＆
//链接：https://leetcode.cn/problems/palindrome-linked-list/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。