class LRUCache {
public:

    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int v) {
            this->key = key;
            this->val = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    int limit;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->limit = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove any node from DLL
    void removeNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Add node just after head
    void addheadnext(Node* newNode) {

        Node* temp = head->next;

        head->next = newNode;

        newNode->prev = head;
        newNode->next = temp;

        temp->prev = newNode;
    }

    int get(int key) {

        // Key not found
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        // Remove from current position
        removeNode(node);
        // Add to front
        addheadnext(node);
        return node->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            // Update value
            node->val = value;
            // Move to front
            removeNode(node);
            addheadnext(node);
            return;
        }

        // Cache is full
        if (mp.size() == limit) {
            // LRU node
            Node* lru = tail->prev;
            // Remove from DLL
            removeNode(lru);
            // Remove from map
            mp.erase(lru->key);
            delete lru;
        }

        // Create new node
        Node* newNode = new Node(key, value);
        // Add to DLL
        addheadnext(newNode);
        // Add to map
        mp[key] = newNode;
    }
};