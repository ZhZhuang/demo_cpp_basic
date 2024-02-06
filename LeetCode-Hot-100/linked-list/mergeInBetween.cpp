//
// Created by Administrator on 2024/1/13.
//

// 1669. 合并两个链表

// 本题的边界条件比较简单

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *fast , *low;
        ListNode *p2 = list2;
        fast = low = list1;
        int dist = b-a+1;
        for(int i=0;i<dist;i++){
            fast = fast->next;
        }
        for(int i=0;i<a-1;i++){
            low = low->next;
            fast = fast->next;
        }
        while(p2->next){
            p2 = p2->next;
        }

        low->next = list2;
        p2->next = fast->next;
        fast->next = p2;
        return list1;
    }
};