//
// Created by Administrator on 2023/11/27.
//

// 分析：本题难度不大，类似于合并两个有序链表

// 给你两个 非空 的链表，表示两个非负的整数。
// 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode *head = new(ListNode);
    ListNode *cur = head;
    int t =0;   // 进位
    while(p1 && p2){
        int sum = p1->val + p2->val;
        if(t == 1){
            sum = sum +1;
        }
        int t1 = sum%10;   // 当前位
        t = sum / 10;
        ListNode *tnode = new(ListNode);
        tnode->val = t1;
        cur->next = tnode;
        cur = cur->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1){
        int sum = p1->val;
        if(t == 1){
            sum = sum +1;
        }
        int t1 = sum%10;   // 当前位
        t = sum / 10;
        ListNode *tnode = new(ListNode);
        tnode->val = t1;
        cur->next = tnode;
        cur = cur->next;
        p1 = p1->next;
    }
    while(p2){
        int sum = p2->val;
        if(t == 1){
            sum = sum +1;
        }
        int t1 = sum%10;   // 当前位
        t = sum / 10;
        ListNode *tnode = new(ListNode);
        tnode->val = t1;
        cur->next = tnode;
        cur = cur->next;
        p2 = p2->next;
    }
    // 最后判断是否有进位
    if(t){
        ListNode *tnode = new(ListNode);
        tnode->val = 1;
        cur->next = tnode;
        cur = cur->next;
    }
    cur->next = nullptr;
    return head->next;
}