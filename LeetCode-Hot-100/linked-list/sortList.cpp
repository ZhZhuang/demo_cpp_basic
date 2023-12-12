//
// Created by Administrator on 2023/11/28.
//

// 本题：要求在 O(n log n) 时间复杂度 和 常数级空间复杂度下
// 暴力思路：遍历，排序  ， 不能这样！！！
// 面试官说 回去等通知，阁下应当如何应对。
// 正解：归并排序


#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* sortList(ListNode* head) {
    vector<int> v;
    ListNode *phead = new ListNode(0);
    ListNode * p = head, *cur = phead;
    while (p){
        v.push_back(p->val);
        p = p->next;
    }
    sort(v.begin(),v.end());
    for(int &i : v){
        ListNode * t = new ListNode(i);
        cur->next = t;
        cur = cur->next;
    }
    return phead->next;
}


// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/sort-list/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。