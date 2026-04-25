struct Node {
      pair<int,int> val;
      Node *next;
      Node *prev;
      Node() : val({0,0}), next(nullptr), prev(nullptr) {}
      Node(pair<int,int> x) : val(x), next(nullptr), prev(nullptr) {}
      Node(pair<int,int> x, Node *next) : val(x), next(next), prev(nullptr) {}
      Node(pair<int,int> x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
  };

class LRUCache {
public:
    unordered_map<int, Node*> nodemap;
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(nodemap.find(key)==nodemap.end()){
            return -1;
        }

        Node* keynode = nodemap[key];
        if(keynode->prev != nullptr){
            if (keynode == tail) tail = keynode->prev;
            keynode->prev->next = keynode->next;
            if(keynode->next != nullptr)
                keynode->next->prev = keynode->prev;
            keynode->prev = nullptr;
            keynode->next = head;
            head->prev = keynode;
            head = keynode;
        }

        return keynode->val.second;
    }
    
    void put(int key, int value) {
        if(nodemap.count(key)) {
            nodemap[key]->val.second = value;
            get(key);
            return;
        }
        if(nodemap.size()<capacity){
            Node* newnode = new Node({key,value});
            newnode->next = head;
            if(head) head->prev = newnode;
            head = newnode;
            if(nodemap.size()==0){
                tail = newnode;
            }
            nodemap[key] = newnode;
        }
        else{
            Node* newnode = new Node({key,value});
            newnode->next = head;
            if(head) head->prev = newnode;
            head = newnode;
            nodemap.erase(tail->val.first);
            Node* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = nullptr;
            else head = nullptr; 
            delete temp;
            nodemap[key] = newnode;
        }
    }
};
