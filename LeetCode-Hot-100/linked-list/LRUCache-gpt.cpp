#include <list>
#include <unordered_map>

class LRUCache {
        public:
        LRUCache(int capacity) : capacity(capacity) {
        }

        int get(int key) {
            auto it = cache.find(key);
            if (it == cache.end()) {
                return -1;
            }
            // 将访问过的数据项移到链表头部表示最近使用过
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return it->second->second;
        }

        void put(int key, int value) {
            auto it = cache.find(key);
            if (it != cache.end()) {
                // 如果数据项已存在，则更新值并移到链表头部
                it->second->second = value;
                cacheList.splice(cacheList.begin(), cacheList, it->second);
            } else {
                if (cache.size() >= capacity) {
                    // 如果缓存已满，则淘汰链表尾部的数据项
                    int key_to_remove = cacheList.back().first;
                    cacheList.pop_back();
                    cache.erase(key_to_remove);
                }
                // 插入新的数据项到链表头部
                cacheList.emplace_front(key, value);
                cache[key] = cacheList.begin();
            }
        }

        private:
        int capacity;
        std::list<std::pair<int, int>> cacheList; // 双向链表，存储键值对
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // 哈希表，存储键和对应的链表迭代器
};
