#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

class Entry {
  public:
    int key;
    int val;

    Entry(int key, int val) : key(key), val(val) {}
};

class LRUCache {
  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        std::list<Entry>::iterator it = map[key];
        list.splice(list.begin(), list, it);
        return it->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            map[key]->val = value;
            list.splice(list.begin(), list, map[key]);
            return;
        }
        list.push_front(Entry(key, value));
        map[key] = list.begin();
        if (list.size() > capacity) {
            Entry to_erase = list.back();
            map.erase(to_erase.key);
            list.pop_back();
        }
    }

  private:
    std::list<Entry> list;
    std::unordered_map<int, std::list<Entry>::iterator> map;
    int capacity;
};
