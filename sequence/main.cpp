#include <iostream>
#include <string>
#include "Sequence.h"

int main(){
    Sequence sequence = Sequence();

    //Alphabetical insertion
    sequence.insert("A");
    sequence.insert("B");
    sequence.insert("C");
    sequence.insert("D");
    sequence.insert("E");
    sequence.insert("F");

    //Insertion at given index
    sequence.insert(0, "G");

    std::cout << "GFEDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Erasure at given index
    sequence.erase(0);

    std::cout << "FEDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Removal of a given value
    sequence.remove("F");

    std::cout << "EDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Get value at given position
    std::string value = "";
    sequence.get(4, value);

    std::cout << "A: " << value << "\n";

    //Set data at given position
    sequence.set(0, value);

    std::cout << "ADCBA: ";
    sequence.print();
    std::cout << "\n";

    //Find given data 
    std::cout << "First instance of A is at: " << sequence.find("A") <<"\n";






}
