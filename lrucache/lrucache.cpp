#include <unordered_map>

class LRUCache {
private:
    
    //DLL Node struct
    struct Node{
        int key, value;
        Node *prev;
        Node *next;
    };
    
    Node *_head;
    Node *_tail;
    
    int _capacity;
    int _occupancy;
    unordered_map <int, Node*> _cache;
    
    void addNodeToFront(int key, int value);
    void moveNodeToFront(int key);
    void deleteLastNode();
    
public:
    
    LRUCache(int capacity);
    int get(int key); 
    void put(int key, int value);
    
};

LRUCache::LRUCache(int capacity){
    if (capacity <= 0) exit(EXIT_FAILURE); //capacity cant be negative or zero
    
    this->_capacity = capacity;
    _occupancy = 0;
    
    //DLL initialization
        
    _head = new Node;
    _tail = new Node;
        
    _head->prev = nullptr;
    _head->next = _tail;
    _tail->prev = _head;
    _tail->next = nullptr;
}

void LRUCache::addNodeToFront(int key, int value){
    //new key adds new node to front of DLL
    _cache[key] = new Node; //allocate memory for a cache node
    _cache[key]->key = key; //node key = key 
    _cache[key]->value = value; //node value = value
    
    //connecting cache to DLL
    _cache[key]->prev = _head; 
    _cache[key]->next = _head->next;
            
    //shifting other DLL values
    (_head->next)->prev = _cache[key];
    _head->next = _cache[key];
}

void LRUCache::moveNodeToFront(int key){
    //shift frequency map if cache key isnt already head->next
    if (_cache[key] != _head->next){ 
                
        //other nodes bypass cache[key]
        (_cache[key]->prev)->next = _cache[key]->next;
        (_cache[key]->next)->prev = _cache[key]->prev;
                
        //cache[key] becomes head->next                
        _cache[key]->next = _head->next;
        _cache[key]->prev = _head;
        (_head->next)->prev = _cache[key];
        _head->next = _cache[key];
    }
}

void LRUCache::deleteLastNode(){
    //remove tail->prev from DLL
    Node *temp;
    temp = _tail->prev; //store tail->prev in temp to prevent memory leak
    ((_tail->prev)->prev)->next = _tail;
    (_tail->prev) = ((_tail->prev)->prev); 
    
    //remove from map and deallocate memory
    _cache.erase(temp->key);
    delete temp;
}

int LRUCache::get(int key){
    if (_cache.find(key) != _cache.end()){
        
        //move key to front of DLL
        moveNodeToFront(key);
        
        return _cache[key]->value;
    }
    else return -1;
}

void LRUCache::put(int key, int value){
    //key already exists case
    if (_cache.find(key) != _cache.end()){
        
        //modify value in cache map
        _cache[key]->value = value;
        
        //move key to front of DLL
        moveNodeToFront(key);
            
    }
    //key doesn't exist but we haven't reached capacity
    else if (_occupancy < _capacity){
            
            //add key to front of DLL
            addNodeToFront(key, value);
            
            //increment occupancy
            _occupancy++;
    }
    //key doesn't exist and we've reached capacity
    else{
            
        //remove tail->prev from DLL
        deleteLastNode();
        
        //add key to front of DLL
        addNodeToFront(key, value);
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
