class LRUCache {
public:
    int cap,size = 0;
    class Node {
      public:
        int key;
        int val;
        Node* prev = NULL,*next = NULL;
        Node(int _key,int _val) {
            key = _key;
            val = _val;
        }
    };
    
    unordered_map<int,Node*> map;
    
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node *node) {
        Node* temp = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = temp;
        temp -> prev = node;
    }
    
    void deleteNode(Node *node) {
        Node *delPrev = node -> prev;
        Node *delNext = node -> next;
        
        delPrev -> next = delNext;
        delNext -> prev = delPrev;
        
        delete node;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node* temp = map[key];
            Node* newNode = new Node(key,temp->val);
            deleteNode(temp);
            addNode(newNode);
            map[key] = newNode;
            return newNode -> val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node* temp = map[key];
            map.erase(key);
            Node* newNode = new Node(key,value);
            deleteNode(temp);
            addNode(newNode);
            map[key] = newNode;
        }
        else {
            size++;
            if(cap < size) {
                map.erase(tail->prev->key);
                deleteNode(tail -> prev);
            }
            Node* temp = new Node(key,value);
            addNode(temp);
            map[key] = temp;
        }
    }
    
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */