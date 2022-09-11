#include <iostream>
#include "Sequence.h"

int main(){
    Sequence sequence = Sequence();
    sequence.insert("First");
    sequence.insert("Hello World!");
    sequence.print();
}
