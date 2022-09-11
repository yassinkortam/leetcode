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

    Node *temp = new Node, *temp2 = new Node;
    temp = _head;
    temp2 = other._head->next;

    while (temp2 != other._tail){
        Node *new_node = new Node;
        new_node->prev = temp;
        new_node->next = _tail;
        _tail->prev = new_node;
        new_node->data = temp2->data;

        temp->next = new_node;
        temp = new_node;
        temp2 = temp2->next;
    }
    temp->next = _tail;
    _tail->prev = temp;
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
    while(erase(pos)) pos++;

    Node *temp = new Node;
    Node *temp2 = new Node;
    temp = _head;
    temp2 = other._head->next;
    while (temp2->next != other._tail){
        Node *new_node = new Node;
        new_node->prev = temp;
        new_node->next = _tail;
        _tail->prev = new_node;
        new_node->data = temp2->data;

        temp->next = new_node;
        temp = temp->next;
        temp2 = temp2->next;
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
    if (pos >= _size) return -1;

    Node *new_node = new Node; //allocate memory for new node
    new_node->data = value; 

    Node *temp = new Node; //allocate memory for temp node (suceeding node to new node)
    temp = _head->next;
    for (int i=0; i<pos; i++){
        temp = temp->next;
    }

    new_node->next = temp; 
    new_node->prev = temp->prev;

    (temp->prev)->next = new_node;
    temp->prev = new_node; 

    _size ++; //increase size by 1
    return pos;
}

int Sequence::insert(const ItemType& value){
    int p = 0;
    if (_head->next == _tail){ //empty sequence case
      Node *new_node = new Node;
      new_node->data = value;
      new_node->prev = _head;
      new_node->next = _tail;

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
            Node *new_node = new Node;
            new_node->data = value;
            new_node->prev = temp;
            new_node->next = _tail;

            temp->next = new_node;
            _tail->prev = new_node;

            _size++;
            return p; 
        }
    }

    Node *new_node = new Node;
    new_node->data = value;
    new_node->prev = temp->prev;
    new_node->next = temp;

    (temp->prev)->next = new_node;
    temp->prev = new_node;

    _size++;
    return p;
    
}

bool Sequence::erase(int pos){
    if (pos >= _size) return false;

    Node *temp = new Node;
    temp = _head->next;

    for (int i=0; i<pos; i++){
        temp = temp->next;
    }
    if (temp == _tail) return false; // safety measure
    (temp->next)->prev = temp->prev;
    (temp->prev)->next = temp->next;
    free(temp);
    _size--;
    return true;
}

int Sequence::remove(const ItemType& value){
    if (_size == 0) return 0;

    int pos = 0;
    Node *temp = new Node;
    temp = _head->next;

    while (temp != _tail){
        if (temp->data == value){
            (temp->next)->prev = temp->prev;
            (temp->prev)->next = temp->next;
            free(temp);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return 0;
}

bool Sequence::get(int pos, ItemType& value) const{
    if (pos >= _size) return false;

    Node *temp = new Node;
    temp = _head->next;

    for (int i=0; i<pos; i++){
        temp = temp->next;
    }
    if (temp != _tail && temp != _head) value = temp->data; //safety
    else return false;
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

    temp = _head; //save original head
    _head->next = other._head->next; 
    _head->prev = nullptr;
    (other._head->next)->prev = _head;

    other._head->next = temp->next;
    other._head->prev = nullptr;
    (temp->next)->prev = other._head;

    temp = _tail;
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

    result.get(result.size()-1, value);
    result.insert(result.size()-1, value); //adding a padding

    int i=0;
    while (seq1.get(pos, value)){
        if (result.insert(i, value) != -1){
            i += 2;
        }
        else{
            result.insert(result.size()-1, value);
        }
    }
    result.erase(result.size()-1); //removing the padding
}
