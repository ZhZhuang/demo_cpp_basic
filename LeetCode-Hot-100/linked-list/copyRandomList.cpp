//
// Created by Administrator on 2023/11/28.
//

// 仔细思考：没做对，做了三遍了！！！！
// 技巧：哈希表，用于简历元链表与目标链表的映射关系

#include <cstddef>  // NULL的定义
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node *p = head;
        while (p){
            map[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        while (p){
            map[p]->next = map[p->next];
            map[p]->random = map[p->random];
            p = p->next;
        }
        return map[head];
    }

    Node* copyRandomList_1(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return map[head];
    }
    //
    //作者：Krahets
    //        链接：https://leetcode.cn/problems/copy-list-with-random-pointer/
    //        来源：力扣（LeetCode）
    //著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};