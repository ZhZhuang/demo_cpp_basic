//
// Created by Administrator on 2023/11/26.
//

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * head = new(ListNode);    // 伪头节点
    ListNode *p1 = list1, *p2 = list2, *cur = head;
    while (p1 && p2){
        if(p1->val < p2->val){
            ListNode * t = new(ListNode);
            t->val = p1->val;
            cur->next = t;
            cur= cur->next;
            p1 = p1->next;
        } else{
            ListNode * t = new(ListNode);
            t->val = p2->val;
            cur->next = t;
            cur= cur->next;
            p2 = p2->next;
        }
    }
    while(p1){
        ListNode * t = new(ListNode);
        t->val = p1->val;
        cur->next = t;
        cur= cur->next;
        p1 = p1->next;
    }
    while (p2){
        ListNode * t = new(ListNode);
        t->val = p2->val;
        cur->next = t;
        cur= cur->next;
        p2 = p2->next;
    }
    cur = nullptr;
    // 释放内存
    ListNode *t = head;
    head = head->next;
    delete t;
    return head;
}