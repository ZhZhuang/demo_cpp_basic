//
// Created by Administrator on 2023/11/25.
//

// 做了好几遍了，还是记不全

// 方法一：哈希表
// 方法二：双指针

//弄这么多字也没讲明白。若相交，链表A： a+c, 链表B : b+c. a+c+b+c = b+c+a+c 。
//        则会在公共处c起点相遇。若不相交，a +b = b+a 。因此相遇处是NULL


//#include <map>
#include <unordered_map>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //哈希表
        unordered_map<ListNode*,int>mp;
        ListNode* cur1=headA;
        while(cur1){
            mp[cur1]++;
            cur1=cur1->next;
        }
        ListNode* cur2=headB;
        while(cur2){
            if(mp[cur2]) return cur2;
            cur2=cur2->next;
        }
        return nullptr;
    }
};