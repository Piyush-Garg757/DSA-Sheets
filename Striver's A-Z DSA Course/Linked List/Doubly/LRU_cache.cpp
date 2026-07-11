/*LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4*/

class LRUCache
{
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int x, int y)
        {
            key = x;
            value = y;
            prev = nullptr;
            next = nullptr;
        }
    };
    unordered_map<int, Node *> mpp;
    int capacity;
    Node *head;
    Node *tail;
    void deletenode(Node *node)
    {
        Node *prv = node->prev;
        Node *nxt = node->next;
        node->prev->next = nxt;
        node->next->prev = prv;
    }
    void insertnode(Node *node)
    {
        Node *nxt = head->next;
        node->next = nxt;
        nxt->prev = node;
        node->prev = head;
        head->next = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *node = mpp[key];
            deletenode(node);
            insertnode(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            mpp[key]->value = value;
            Node *node = mpp[key];
            deletenode(node);
            insertnode(node);
        }
        else
        {
            if (mpp.size() == capacity)
            {
                Node *node = tail->prev;
                mpp.erase(node->key);
                deletenode(node);
                delete node;
            }
            Node *node = new Node(key, value);
            mpp[key] = node;
            insertnode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// TC - O(1)  SC - O(n)
// Intuiton simple jab bhi kisi node pe kuch operation karo use jaha bhi vo hai vahan se delete karke head ke aage laga do kyuki vo most recently used hai aur jab lear recently used hatana ho to vo obviously tail se pehle vala hoga to use delete kar do   iske liye humne unordered mao liya hai jo key aur node store kare aur doubly linked list li hai