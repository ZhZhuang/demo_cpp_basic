
//146. LRU 缓存
// 动手实现 LRU缓存 （最近最少使用）

// 核心思路：双链表 + 哈希表

// 收获：带头尾指针的双链表好用
#include <unordered_map>
using namespace std;

struct DListNode{
    int key , val;
    DListNode *prev;
    DListNode *next;
    DListNode():key(0),val(0),prev(nullptr),next(nullptr){}
    DListNode(int x,int y):key(x),val(y),prev(nullptr),next(nullptr){}
};


class LRUCache {
public:
    int capacity;
    unordered_map<int,DListNode*> map;
    int size; // 当前大小
    DListNode *head;
    DListNode *tail;

    LRUCache(int capacity) {
        this->capacity =capacity;
        size = 0;
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // 返回key对应的节点的val
        if(map.count(key)){
            DListNode *node = map[key];
            moveToHead(node);
            return node->val;
        } else{
            return -1;
        }
    }

    void put(int key, int value) {
        // 判断是否超容量，如果超过容量删除尾部，删除map项
        // 将value节点放到链表头部
        if(map.count(key)){
            DListNode *node = map[key];
            node->val = value;
            moveToHead(node);
        } else{
            if(size<capacity){
                DListNode *node = new DListNode(key,value);
                addToHead(node);
                map[key] = node;
                size++;
            } else{
                DListNode *temp = removeTail();
                map.erase(temp->key);   // 删除哈希表的一项
                //free(temp);
                delete temp;
                DListNode *node = new DListNode(key,value);
                addToHead(node);
                map[key] = node;
                //size++;
            }
        }

    }

    // --------------  链表操作 ---------------
    void addToHead(DListNode *node){  // 头插法
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void remove(DListNode *node){
        // 带头尾节点，好操作
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    DListNode* removeTail(){
        DListNode *node = tail->prev;
        remove(node);
        return node;
    }
    void moveToHead(DListNode *node){
        remove(node);
        addToHead(node);
    }
};