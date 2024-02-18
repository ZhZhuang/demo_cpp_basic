//方法一：哈希
//方法二：快慢指针 Floyd's Tortoise and Hare


#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;  // 没有节点或只有一个节点，不可能有环
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) {
            return true;  // 指针相遇，说明有环
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;  // 快指针到达链表末尾，说明没有环
}

int main() {
    // 创建一个有环的链表
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // 4->2 形成环

    if (hasCycle(head)) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list doesn't have a cycle." << std::endl;
    }

    // 释放链表内存
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
