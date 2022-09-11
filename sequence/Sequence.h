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
    Sequence(); 
    // Create an empty sequence (i.e., one with no items)
    void print() const; 
    //Prints the entire sequence
    bool empty() const; 
    // Return true if the sequence is empty, otherwise false.
    int size() const;
     // Return the number of items in the sequence.
    int insert(int pos, const ItemType& value); 
        // Insert value into the sequence so that it becomes the item at
        // position pos.  The original item at position pos and those that
        // follow it end up at positions one higher than they were at before.
        // Return pos if 0 <= pos < size() and the value could be
        // inserted.  (It might not be, if the sequence has a fixed capacity,
        // e.g., because it's implemented using a fixed-size array.)  
        //Otherwise,
        // leave the sequence unchanged and return -1.  Notice that
        // if pos is equal to size(), the value is inserted at the end.
    int insert(const ItemType& value);
        // Let p be the smallest integer such that value <= the item at
        // position p in the sequence; if no such item exists (i.e.,
        // value > all items in the sequence), let p be size().  Insert
        // value into the sequence so that it becomes the item at position
        // p.  The original item at position p and those that follow it end
        // up at positions one higher than before.  Return p if the value
        // was actually inserted.  Return -1 if the value was not inserted
        // (perhaps because the sequence has a fixed capacity and is full).
    bool erase(int pos);
        // If 0 <= pos < size(), remove the item at position pos from
        // the sequence (so that all items that followed that item end up at
        // positions one lower than they were at before), and return true.
        // Otherwise, leave the sequence unchanged and return false.
    int remove(const ItemType& value);
        // Erase all items from the sequence that == value.  Return the
        // number of items removed (which will be 0 if no item == value).
    bool get(int pos, ItemType& value) const;
        // If 0 <= pos < size(), copy into value the item at position pos
        // of the sequence and return true.  Otherwise, leave value unchanged
        // and return false.
    bool set(int pos, const ItemType& value);
        // If 0 <= pos < size(), replace the item at position pos in the
        // sequence with value and return true.  Otherwise, leave the sequence
        // unchanged and return false.
    int find(const ItemType& value) const;
        // Let p be the smallest integer such that value == the item at
        // position p in the sequence; if no such item exists, let p be -1.
        // Return p.
    void swap(Sequence& other);
        // Exchange the contents of this sequence with the other one.
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

void Sequence::print() const{
    Node *temp = new Node;
    temp = _head->next;
    while (temp != _tail){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
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
    if (temp->data <= value){ //while loop will only break if this is true anyways
        Node *new_node = new Node;
        new_node->data = value;
        new_node->prev = temp->prev;
        new_node->next = temp;

        (temp->prev)->next = new_node;
        temp->prev = new_node;

        _size++;
        return p;
    }
    return -1; //will never be reached anyways
}

