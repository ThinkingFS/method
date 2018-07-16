#ifndef ArrayClass_header
#define ArrayClass_header

#include <memory>

using std::unique_ptr;
using std::make_unique;



class ArrayClass
{
public:
    // Constructors and Destructors
    
    // Default constructor
    // POST: Created an ArrayClass object with an array of size def_size
    // Compiler default suffices (see variable initializations at end of header)
    ArrayClass() = default;
    
    // Constructor
    // PRE: capacity > 0
    // POST: Created an ArrayClass object with an array of size capacity
    // PARAM: capacity = size of the array to allocate
    ArrayClass(int capacity);
    
    // Destructor
    // POST: All dynamic memory associated with object de-allocated
    /*~ArrayClass();*/
    
    // Set the value of the next free element
    // PRE: currentSize < arraySize
    // POST: Element at index currentSize set to value
    // PARAM: value = value to be set
    void insert(int value);
    
    // Return an element's value
    // PRE: 0 <= i < arraySize
    // POST: Returned the value at index i
    // PARAM: i = index of value to be returned
    int get(int i) const;
    
    // Set an element's value
    // PRE: 0 <= i < arraySize
    // POST: Element at index i set to value
    // PARAM: i = index of element to be changed
    //        value = value to be set
    void set(int i, int value);
    
    // POST: Return the currently allocated space
    int capacity() const;
    
    // POST: Return the number of elements
    int size() const;

    // The default capacity
    static constexpr int def_capacity {10};
    
private:
    int arrSize {def_capacity};
    int currentSize {0};
    //int* arr {new int[def_capacity]};
    unique_ptr<int[]> arr {make_unique<int[]>(def_capacity)};
};

#endif