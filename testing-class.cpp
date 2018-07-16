#include <iostream>

#include "ArrayClass.h"

using std::cout;
using std::endl;
//using std:unique_ptr;
//using std::make_unique;

// Function Prototype
void arrayClassTest();

// Main function that is called when the program is executed
int main() {
    arrayClassTest();
    
    return 0;
}

void arrayClassTest() {
    auto ac1 = ArrayClass{};
    
    // Insert the values 1 to 7 in ac1
    for (auto i = int{0}; i < 7; ++i) {
        ac1.insert(i+1);
    }
    
    // Change the value with index 3 to 13
    ac1.set(3, 13);
    // Attempt to change the value with index 9 to 22
    // Nothing happens since it is not an existing value
    ac1.set(9, 22);
    
    // Print the values in reverse order
    // Should print: 7 6 5 13 3 2 1
    for (auto i = ac1.size()-1; i >= 0; i--) {
        cout << ac1.get(i) << " ";
    }
    cout << endl;
    
    auto ac2 = ArrayClass{3}; // Initialization, so enclose in {}
    
    // Insert the values 2 and 4 in ac2
    ac2.insert(2);
    ac2.insert(4);

    //ac1.get(20);
    //testing getting invalid index
    
    // Print current and max size of ac1 and ac2
    cout << "ac1: current size = " << ac1.size();
    cout << ", capacity = " << ac1.capacity() << endl;
    cout << "ac2: current size = " << ac2.size();
    cout << ", capacity = " << ac2.capacity() << endl;

    // Get the capacity of a default object
    cout << "Default capacity: " << ArrayClass::def_capacity << endl;
}
