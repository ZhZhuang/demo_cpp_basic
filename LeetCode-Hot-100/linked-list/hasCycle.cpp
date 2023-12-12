//
// Created by Administrator on 2023/11/26.
//

// 放到哈希表中
#include <unordered_set>
#include <unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//bool hasCycle(ListNode *head) {
//    unordered_set<ListNode*> set;
//    ListNode *cur = head;
//    while (cur!= nullptr){
//        if(set.count(cur) > 0){
//            return true;
//        }else{
//            set.insert(cur);
//        }
//        cur = cur->next;
//    }
//    return false;
//}

bool hasCycle(ListNode *head) {
    unordered_set<ListNode*, int> mp;
    ListNode *cur = head;
    while (cur!= nullptr){
        if(mp[cur] > 0){
            return true;
        }else{
            mp[cur]++;
        }
        cur = cur->next;
    }
    return false;
}

ListNode *detectCycle(ListNode *head) {
    unordered_map<ListNode*, int> map;
    ListNode *p = head;
    while (p){
        if(map[p] > 0){
            return p;
        }else{
            map[p]++;
        }
        p = p->next;
    }
    return nullptr;
}