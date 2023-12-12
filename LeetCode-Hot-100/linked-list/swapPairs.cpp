//
// Created by Administrator on 2023/11/28.
//

// 两两交换
// 仔细思考, 第一遍没写对！！！

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* temp_head = new ListNode(0);//定义一个虚拟头节点
    ListNode* a;
    temp_head->next = head;
    a = temp_head;
    while(a->next != NULL && a->next->next != NULL){
        ListNode* temp;
        temp = a->next->next->next;
        //将1指向3，3指向2，2指向4
        a->next = head->next;
        a->next->next = head;
        head->next = temp;
        //1往后以两格，2往后移两格
        a = a->next->next;
        head = temp;
    }
    return temp_head->next;
}



ListNode* swapPairs_error(ListNode* head) {
    if(head == nullptr){
        return nullptr;
    }
    ListNode *slow , *fast;
    ListNode *phead = new ListNode(0,head);
    ListNode *temp = nullptr;
    slow = fast = phead;
    fast = phead->next;
    while (fast && fast->next){
        //temp = slow->next;
        //slow->next = fast;
        //temp->next = fast->next;
        //fast->next = temp;
        slow->next = fast->next;
        fast->next = fast->next->next;
        slow->next->next = fast;

        slow = fast;
        if(slow->next){
            break;
        }
        fast = fast->next;
    }
    return phead->next;
}