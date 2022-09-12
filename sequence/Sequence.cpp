#ifndef SEQUENCE
#define SEQUENCE
#include "Sequence.h"
#endif

//Member functions

Sequence::Sequence(){
    _head = new Node;
    _tail = new Node;
    _head->prev = nullptr;
    _head->next = _tail;
    _tail->prev = _head;
    _tail->next = nullptr;
    _size = 0;
}

Sequence::Sequence(const Sequence& other){
    _head = new Node;
    _tail = new Node;
    _head->prev = nullptr;
    _head->next = _tail;
    _tail->prev = _head;
    _tail->next = nullptr;
    _size = 0;

    if (other.empty()) return; 

    Node *target = new Node, *source = new Node;
    target = _head;
    source = other._head->next;

    while (source != other._tail){
        Node *new_node = new Node;
        new_node->prev = target; //new node comes after target
        new_node->next = _tail; //new node is added before tail
        new_node->data = source->data; 
        _tail->prev = new_node; //tail points back to new_node 
        target->next = new_node; //target points forward to new_node
        target = new_node; //move temp forward
        source = source->next; //move source forward
    }
    target->next = _tail;
    _tail->prev = target;
    _size = other._size;
}

Sequence::~Sequence(){
    int pos = 0;
    while(erase(pos)) pos++;
    free(_head);
    free(_tail);
}

Sequence& Sequence::operator=(const Sequence& other){
    int pos = 0;
    while(erase(pos)) pos++; //clear target

    Node *target = new Node; //points to target
    Node *source = new Node; //points to source sequence
    target = _head; //target lags
    source = other._head->next; //source sequence leads
    while (source != other._tail){  //stop at tail
        Node *new_node = new Node;
        new_node->prev = target; //target points back to temp
        new_node->next = _tail; //target added right behind tail
        new_node->data = source->data; //target has source data

        _tail->prev = new_node; //tail points back to new node
        target->next = new_node; //temp points to new node

        target = target->next; //move temp forward
        source = source->next; //move temp2 forward
    }
    _size = other._size;
    return *this;
}

void Sequence::print() const{
    if (empty()){
        std::cout << "[]";
        return;
    }
    Node *temp = new Node;
    temp = _head->next;
    std::cout << "[";
    while (temp->next != _tail){
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << temp->data << "]";
}

int Sequence::size() const{
    return _size;
}

bool Sequence::empty() const{
    if (_head->next == _tail) return true;
    return false;
}

int Sequence::insert(int pos, const ItemType& value){
    if (pos >= _size) return -1; //if the position is not in sequence

    Node *temp = new Node; //allocate memory for temp node (suceeding node to new node)
    temp = _head; //pos corresponds to steps from head
    for (int i=0; i<pos; i++){
        if (temp != _tail) temp = temp->next;
        else return -1; //safety case
    }

    Node *new_node = new Node; //allocate memory for new node
    new_node->next = temp->next;  
    new_node->prev = temp; 
    new_node->data = value;  

    temp->next = new_node; 
    (new_node->next)->prev = new_node; 

    _size ++; //increase size by 1
    return pos;
}

int Sequence::insert(const ItemType& value){
    int p = 0;
    if (_head->next == _tail){ //Known good: empty sequence case 
      Node *new_node = new Node;
      new_node->prev = _head;
      new_node->next = _tail;
      new_node->data = value;

      _head->next = new_node;
      _tail->prev = new_node;

      _size++;
      return p;
    }
    
    Node *temp = new Node;
    temp = _head->next;
    while (value < temp->data){
        if (temp->next != _tail){ //only iterate to next node if its not the last one
            temp = temp->next; 
            p++;
        }
        else{ //if we reach tail and no data greater than value
            break;
        }
    }

    Node *new_node = new Node;
    new_node->prev = temp->prev;
    new_node->next = temp;
    new_node->data = value;

    (temp->prev)->next = new_node;
    temp->prev = new_node;

    _size++;
    return p;
    
}

bool Sequence::erase(int pos){
    if (pos >= _size) return false;

    Node *temp = new Node;
    temp = _head;

    if (temp->next == _tail) return false;

    for (int i=0; i<=pos; i++){
        if (temp->next != _tail) temp = temp->next;
    }
    (temp->next)->prev = temp->prev;
    (temp->prev)->next = temp->next;
    free(temp);
    _size--;
    return true;
}

int Sequence::remove(const ItemType& value){
    if (_size == 0) return 0;

    int pos = 0;
    int num_removed = 0;
    Node *temp = new Node;
    temp = _head->next;

    while (temp != _tail){
        if (temp->data == value){
            (temp->next)->prev = temp->prev;
            (temp->prev)->next = temp->next;
            free(temp);
            num_removed++;
        }
        temp = temp->next;
        pos++;
    }
    return num_removed;
}

bool Sequence::get(int pos, ItemType& value) const{
    if (pos >= _size) return false;

    Node *temp = new Node;
    temp = _head->next;

    for (int i=0; i<pos; i++){
        if (temp != _tail) temp = temp->next;
        else return false;
    }
    value = temp->data; //safety
    return true;
}

bool Sequence::set(int pos, const ItemType& value){
    if (pos >= _size) return false;

    Node *temp = new Node;
    temp = _head->next;

    for (int i=0; i<pos; i++){
        temp = temp->next;
    }

    temp->data = value;
    return true;
}

int Sequence::find(const ItemType& value) const{
    if (_size == 0) return -1;

    int p = 0;
    Node *temp = new Node;
    temp = _head->next;

    while (temp != _tail){
        if (temp->data == value){
            return p;
        }
        temp = temp->next;
        p++;
    }
    return -1;
}

void Sequence::swap(Sequence& other){
    Node *temp = new Node;
    int sizer;

    //save original head
    temp->next = _head->next;
    temp->prev = _head->prev;

    _head->next = other._head->next; 
    _head->prev = nullptr;
    (other._head->next)->prev = _head;

    other._head->next = temp->next;
    other._head->prev = nullptr;
    (temp->next)->prev = other._head;

    //save original tail
    temp->next = _tail->next;
    temp->prev = _tail->prev;

    _tail->next = nullptr;
    _tail->prev = other._tail->prev;
    (other._tail->prev)->next = _tail;

    other._tail->next = nullptr;
    other._tail->prev = temp->prev;
    (temp->prev)->next = other._tail;

    sizer = _size;
    _size = other._size;
    other._size = sizer;
}

//Non-member functions

int subsequence(const Sequence& source, const Sequence& sub){
    if (source.size() < sub.size()) return -1;
    int source_pos = 0;
    int sub_pos = 0;
    ItemType source_value;
    ItemType sub_value;

    while(source.get(source_pos, source_value)){
        if (sub.get(sub_pos, sub_value)){
            if (sub_value == source_value){
                sub_pos++;
            }
            else{
                sub_pos = 0;
            }
            source_pos++;
        }
        else{
            return source_pos - sub.size();
        }
    }
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    result = seq2;
    int pos = 0;
    ItemType value;

    int i=0;
    while (seq1.get(pos, value)){
        if (result.insert(i, value) != -1){
            i += 2;
        }
        else{
            result.insert(result.size()-1, value);
        }
        pos++;
    }
}
