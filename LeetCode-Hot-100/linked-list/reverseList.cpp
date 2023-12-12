//
// Created by Administrator on 2023/11/25.
//


// C++11标准引入的特性,nullptr, 结构体中包含构造函数
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *cur = head, *pre = nullptr;
    while(cur != nullptr) {
        ListNode* tmp = cur->next; // 暂存后继节点 cur.next
        cur->next = pre;           // 修改 next 引用指向
        pre = cur;                 // pre 暂存 cur
        cur = tmp;                 // cur 访问下一节点
    }
    return pre;
}



//#include <stdlib.h>
//struct ListNode {
//    int val;
//    struct ListNode *next;
//};
//
//struct ListNode* reverseList(struct ListNode* head) {
//    if(head == NULL){
//        return NULL;
//    }
//    // 伪头节点
//    struct ListNode *phead =NULL; // malloc(sizeof(struct ListNode));
//    //phead = head;
//    // 改进，不用伪头节点
//    struct ListNode *p = head;
//    //phead->next = NULL;
//    while(p!=NULL){
//        struct ListNode *t = p->next;
//        p->next = phead;
//        phead = p;
//        p = t;
//    }
//    return phead;
//}