//
// Created by Administrator on 2024/1/9.
//

//160. 相交链表

/*
 * 思路一，使用集合存储, 比较容易想
 * 思路二，同时遍历两个链表，交替遍历，不容易想，代码容易写错
 */

#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *,int> map;
        ListNode *p = headA;
        while (p!= nullptr){
            map[p]++;
            p = p->next;
        }
        p = headB;
        while (p!= nullptr){
            if(map[p] != 0){
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};

class Solution_2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *p1 = headA, *p2 = headB;
        while(p1 != p2){
            if(p1 == nullptr)
                p1 = headB;
            else
                p1= p1->next;
            if(p2 == nullptr)
                p2 = headA;
            else
                p2= p2->next;
        }
        return p1;
    }
};