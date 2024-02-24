//
// Created by Administrator on 2024/2/24.
//


#include <stdio.h>
#include <stdlib.h>

// 定义双链表节点结构
typedef struct DListNode {
    int data;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

//广州敏视数码科技有限公司-嵌入式笔试题
//双链表的逆置
// 现场编写
DListNode * reverse(DListNode * head){
    DListNode * prev=NULL; // 初始化一个prev指针，用于保存当前节点的前一个节点，初始为NULL
    DListNode * con= head; // 初始化一个con指针，用于遍历链表，初始指向头节点
    DListNode * next=NULL; // 初始化一个next指针，用于保存当前节点的下一个节点

    while(con != NULL){ // 遍历链表直到con为NULL
        next = con->next; // 保存当前节点的下一个节点
        con->next = prev; // 将当前节点的next指针指向前一个节点，实现反转

        // 如果prev不为NULL，说明链表中至少有两个节点，需要更新prev的prev指针
        if(prev!=NULL)
            prev->prev = con;

        prev = con; // 将prev移动到当前节点
        con=next; // 将con移动到下一个节点
    }

    prev->prev=NULL; // 反转后，原链表的尾节点现在是新链表的头节点，其prev指针应设置为NULL
    return prev; // 返回新链表的头节点
}


///////////////// 测试 ////////////////////////

// 创建新节点
DListNode* createNode(int data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    if (!newNode) {
        exit(1); // 内存分配失败
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 在双链表末尾添加新节点
void appendNode(DListNode** head, int data) {
    DListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    DListNode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// 打印双链表
void printList(DListNode* head) {
    DListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//// 逆置双链表
//void reverseList(DListNode** head) {
//    DListNode* prev = NULL;
//    DListNode* current = *head;
//    DListNode* next = NULL;
//
//    while (current != NULL) {
//        next = current->next; // 保存下一个节点
//        current->next = prev; // 反转当前节点的指针
//        current->prev = next; // 如果存在下一个节点，更新其prev指针
//        prev = current; // 移动到下一个节点
//        current = next;
//    }
//    *head = prev; // 更新头节点
//}

int main() {
    DListNode* head = NULL;

    // 添加节点到双链表
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Original List: ");
    printList(head);

    // 逆置双链表
    //reverseList(&head);
    head = reverse(head);

    printf("Reversed List: ");
    printList(head);

    // 释放双链表内存
    while (head != NULL) {
        DListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}