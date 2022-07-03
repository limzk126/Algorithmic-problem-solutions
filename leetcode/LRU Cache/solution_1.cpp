#include <unordered_map>
using namespace std;

class LRUCache {
    public:
        struct Node {
            int key;
            int value;
            Node* next;
            Node* prev;

            Node(int key, int value): key(key), value(value), next(nullptr), prev(nullptr) {}
        };

        Node* head;
        Node* tail;
        unordered_map<int, Node*> mp;

        int capacity;
        int cur_capacity;

        LRUCache(int capacity) {
            this->capacity = capacity; 
            cur_capacity = 0;
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key) {
            if (mp.find(key) == mp.end()) {
                return -1;
            }
            
            Node* node = mp[key];
            removeNode(node);
            insertFront(node);

            return mp[key]->value;
        }

        void put(int key, int value) {
            if (mp.find(key) == mp.end()) {
                if (cur_capacity == capacity) {
                    removeLast();
                }

                Node* node = new Node(key, value);
                insertFront(node);
                return;
            }
            
            Node* node = new Node(key, value);
            removeNode(mp[key]);
            insertFront(node);
        }

        void insertFront(Node* node) {
            Node* next = head->next;
            head->next = node;
            node->next = next;
            next->prev = node;
            node->prev = head;

            mp[node->key] = node;

            ++cur_capacity;
        }

        void removeNode(Node* node) {
            Node* prev = node->prev;
            Node* next = node->next;
            prev->next = next;
            next->prev = prev;

            mp.erase(node->key);
            
            --cur_capacity;
        }

        void removeLast() {
            Node* prev = tail->prev->prev;
            if (prev == nullptr) return;

            int key_to_remove = tail->prev->key;
            mp.erase(key_to_remove);
            prev->next = tail;
            tail->prev = prev;
            
            --cur_capacity;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
