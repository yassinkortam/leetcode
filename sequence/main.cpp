#include <iostream>
#include <string>
#include "Sequence.cpp"

int main(){
    Sequence sequence = Sequence();

    std::cout << "Visual Sequence Test \n";

    //Alphabetical insertion
    sequence.insert("A");
    sequence.insert("B");
    sequence.insert("C");
    sequence.insert("D");
    sequence.insert("E");
    sequence.insert("F");

    //Insertion at given index
    std::cout << "\n Insertion at given index \n";
    std::cout << "Pass: " << sequence.insert(0, "G"); //true
    std::cout << ", NoPass: " << sequence.insert(10, "X")  << "\n"; //false

    std::cout << "GFEDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Erasure at given index
    std::cout << "\n Erasure at given index \n";
    std::cout << "Pass: " << sequence.erase(0); //true
    std::cout << ", NoPass: " << sequence.erase(10)  << "\n"; //false

    std::cout << "FEDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Removal of a given value
    std::cout << "\n Removal of a given value \n";
    std::cout << "Pass: " << sequence.remove("F");
    std::cout << ", NoPass: " << sequence.remove("ي")  << "\n";

    std::cout << "EDCBA: ";
    sequence.print();
    std::cout << "\n";

    //Get value at given position
    std::cout << "\n Get value at given position \n";
    std::string value1 = "";
    std::cout << "Pass: " << sequence.get(4, value1);
    std::cout << ", NoPass: " << sequence.get(10, value1) << "\n";

    std::cout << "A: " << value1 << "\n";

    //Set data at given position
    std::cout << "\n Set data at given position \n";
    std::cout << "Pass: " << sequence.set(0, value1);
    std::cout << ", NoPass: " << sequence.set(10, value1) << "\n";

    std::cout << "ADCBA: ";
    sequence.print();
    std::cout << "\n";

    //Find given data 
    std::cout << "\n Find given data \n";
    std::cout << "No instance of Z: " << sequence.find("Z") << "\n";
    std::cout << "First instance of A is at: " << sequence.find("A") << "\n";

    //Copy constructor test
    std::cout << "\n Copy constructor test \n";
    Sequence copy = Sequence(sequence);
    copy.print();
    std::cout << " = ";
    sequence.print();
    std::cout << "\n";

    //Assignment operator test
    std::cout << "\n Assignemnt operator test \n";
    Sequence copy2 = copy;
    copy.print();
    std::cout << " = ";
    copy2.print();
    std::cout << "\n";

    //Swap two sequences
    std::cout << "\n Swap two sequences \n";
    Sequence other = Sequence();
    other.insert("X");
    other.insert("Y");
    other.insert("Z");

    sequence.swap(other);
    std::cout << "Sequence: ";
    sequence.print();
    std::cout << "\nOther: ";
    other.print();
    std::cout << "\n";

    //Subsequence test
    Sequence sub = Sequence();
    sub.insert("X");
    std::cout << "\n Subsequence test \n";
    sub.print();
    std::cout << " starts at " << subsequence(sequence, sub) << " in ";
    sequence.print();
    std::cout << "\n";

    //Interleave test 
    Sequence interleaved = Sequence();
    std::cout << "\n Interleave test \n";
    std::cout << "Above interleaves to: ";
    interleave(sub, sequence, interleaved);
    interleaved.print();

    //Sequence test 2 
    Sequence a, b, c;
    assert(a.size() == 0); //test size
    assert(a.empty()); //test empty

    assert(a.remove("nothing") == 0); //test remove | empty case
    assert(!a.erase(0)); //test erase | empty case

    assert(a.find("nothing") == -1); //test find | empty case

    assert(a.insert(1, "A") == -1); //test insert | out of index case

    assert(a.insert("B") == 0); //test insert | normal case
    assert(a.insert(0, "A") == 0); //test insert | normal case

    assert(a.remove("B") == 1); //test remove | normal case
    assert(a.erase(0)); //test erase | normal case

    std::string value;
    a.insert("A"); a.insert("B"); a.insert("C"); 
    b.insert("X"); b.insert("Y"); b.insert("Z");

    assert(!a.get(4, value)); //test get | out of index case
    assert(!a.set(4, value)); //test set | out of index case

    assert(a.find("A") == 2); //test find | normal case
    assert(a.get(2, value)); //test get | normal case
    assert(a.set(2, value)); //test set | normal case

    c = a;
    b.swap(a);

    assert(subsequence(b, c) == 0); //test swap resulting equivalence and subsequence normal case

    interleave(a, b, c);
    assert(subsequence(a, c) == -1); //test interleave resulting in mix and subsequence false case





















}
