/*
[Medium]
146. LRU Cache
https://leetcode.com/problems/lru-cache/description/
*/

#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val):
            key(key),
            val(val),
            prev(nullptr),
            next(nullptr) {}
    };

public:
    LRUCache(int capacity):
        size(0),
        capacity(capacity) {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }

        Node* node = cache[key];
        removeNode(node);
        addToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) { // cf. find() return an iterator
            Node* node = cache[key];
            removeNode(node);
            node->val = value;
            addToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addToHead(node);
            if (++size > capacity) {
                node = tail->prev;
                cache.erase(node->key); // erase for unordered_map
                removeNode(node);
                --size;
            }
        }
    }

private:
    int size;
    int capacity; // size <= capacity
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */