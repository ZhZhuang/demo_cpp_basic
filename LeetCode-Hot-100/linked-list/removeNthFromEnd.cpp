//
// Created by Administrator on 2023/11/27.
//


// 19. 删除链表的倒数第 N 个结点
// 经典技巧：快慢指针 + 伪头节点
//注意：删除第一个元素的情况，可终止条件while(p->next),定位到前一个元素，
//      画一个示意图


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 注意删除第一个元素
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow, *fast;
    ListNode *phead = new(ListNode);
    phead->next = head;
    slow = fast = phead;
    //fast = phead->next;
    // 定位
    for(int i=1;i<n;i++){
        //slow = slow->next;
        fast = fast->next;
    }
    //
    //while (fast){  注意
    while (fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head->next;
}