#include<iostream>
#include<unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *next, *prev;

    Node()
    {
        this->key = -1;
        this->val = -1;
        this->next = nullptr;
        this->prev = nullptr;
    }
    
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int key, int val, Node* next, Node* prev)
    {
        this->key = key;
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class LRUCache {
    unordered_map<int, Node*>mp; //for O(1) operations
    int capacity;
    Node *head, *tail;
public:
    
    LRUCache(int capacity) {
        mp.clear();
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head; 
    }
    
    void deleteNode(Node* node)
    {
        //T.C --> O(1) [Since its only a links changing operation], no traversal involved
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node)
    {
        //T.C --> O(1) [Since its only a links changing operation], no traversal involved
        Node* nextNode = head->next;

        nextNode->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    
    int get(int key)
    {
        //T.C --> O(1), since unordered_map is used and "deleteNode" & "insertAfterHead" also execute in O(1)

        if(mp.find(key) == mp.end())return -1; //key not found

        //key present in map
        //re-position the node to most-recently used and the return the value.
        //re-position: 
        //step 1. deleteNode from current position
        //step 2. insertAfterHead to make it the first node
        Node* node = mp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }
    
    void put(int key, int value)
    {
        //T.C --> O(1), since unordered_map is used and "deleteNode" & "insertAfterHead" also execute in O(1)

        //key present in map, simply re-position and update the value
        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else
        {
            if(capacity == mp.size())
            {
                Node *nodeToDelete = tail->prev;
                deleteNode(nodeToDelete);
                mp.erase(nodeToDelete->key);
                delete nodeToDelete;
            }
            Node* nodeToInsert = new Node(key, value);
            insertAfterHead(nodeToInsert);
            mp[key] = nodeToInsert;
        }
    }
};


int main()
{
    LRUCache lruCache(3);

    lruCache.put(1, 1);
    lruCache.put(2, 2);
    lruCache.put(3, 3);
    cout<<lruCache.get(3)<<"\n";
    lruCache.put(4, 4);
    cout<<lruCache.get(1)<<"\n";
    cout<<lruCache.get(2)<<"\n";
    lruCache.put(1, 10);
    cout<<lruCache.get(1)<<"\n";
    cout<<lruCache.get(10)<<"\n";
    lruCache.put(5, 5);
    lruCache.put(6, 6);

    return 0;
}