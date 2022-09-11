#ifndef STRING
#define STRING
#include <string>
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

using ItemType = std::string;

struct Node{
    ItemType data;
    Node *next;
    Node *prev;
};

class Sequence{
private:
    Node *_tail;
    Node *_head;
    int _size;
public:
    // Create an empty sequence (i.e., one with no items)
    Sequence(); 

    // Destructor
    ~Sequence();

    //Prints the entire sequence
    void print() const; 

    // Return true if the sequence is empty, otherwise false.
    bool empty() const; 

     // Return the number of items in the sequence.
    int size() const;

    // Insert value into the sequence so that it becomes the item at
    // position pos.  The original item at position pos and those that
    // follow it end up at positions one higher than they were at before.
    // Return pos if 0 <= pos < size() and the value could be
    // inserted.  (It might not be, if the sequence has a fixed capacity,
    // e.g., because it's implemented using a fixed-size array.)  
    //Otherwise,
    // leave the sequence unchanged and return -1.  Notice that
    // if pos is equal to size(), the value is inserted at the end.
    int insert(int pos, const ItemType& value); 

    // Let p be the smallest integer such that value <= the item at
    // position p in the sequence; if no such item exists (i.e.,
    // value > all items in the sequence), let p be size().  Insert
    // value into the sequence so that it becomes the item at position
    // p.  The original item at position p and those that follow it end
    // up at positions one higher than before.  Return p if the value
    // was actually inserted.  Return -1 if the value was not inserted
    // (perhaps because the sequence has a fixed capacity and is full).
    int insert(const ItemType& value);

    // If 0 <= pos < size(), remove the item at position pos from
    // the sequence (so that all items that followed that item end up at
    // positions one lower than they were at before), and return true.
    // Otherwise, leave the sequence unchanged and return false.
    bool erase(int pos);

    // Erase all items from the sequence that == value.  Return the
    // number of items removed (which will be 0 if no item == value).
    int remove(const ItemType& value);
        
    // If 0 <= pos < size(), copy into value the item at position pos
    // of the sequence and return true.  Otherwise, leave value unchanged
    // and return false.
    bool get(int pos, ItemType& value) const;
        
    // If 0 <= pos < size(), replace the item at position pos in the
    // sequence with value and return true.  Otherwise, leave the sequence
    // unchanged and return false.
    bool set(int pos, const ItemType& value);
        
    // Let p be the smallest integer such that value == the item at
    // position p in the sequence; if no such item exists, let p be -1.
    // Return p.
    int find(const ItemType& value) const;
       
    // Exchange the contents of this sequence with the other one.
    void swap(Sequence& other);
};

Sequence::Sequence(){
    _head = new Node;
    _tail = new Node;

    _head->prev = nullptr;
    _head->next = _tail;
    _tail->prev = _head;
    _tail->next = nullptr;

    _size = 0;
}

Sequence::~Sequence(){

}

void Sequence::print() const{
    Node *temp = new Node;
    temp = _head->next;
    std::cout << "[";
    while (temp->next != _tail){
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << temp->data << "]";
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
    temp = _head;

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

    value = temp->data;
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
    

}


