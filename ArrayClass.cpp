#include "ArrayClass.h"
#include "stdlib.h"
#include "stdio.h"
#include <memory>

//using std::unique_ptr;
using std::make_unique;


ArrayClass::ArrayClass(int capacity)
    : arrSize{capacity},
      /*arr{new int[capacity]*/ arr{make_unique<int[]>(capacity)}
{
}

/*ArrayClass::~ArrayClass()
{
    delete [] arr;
}*/


void ArrayClass::insert(int value)
{
    if (currentSize < arrSize) {
        arr[currentSize++] =  value;
    }
    // NOTE - no else - should report error
}

void ArrayClass::set(int i, int value)
{
    if (i >= 0 && i < currentSize) {
        arr[i] =  value;
    }
    // NOTE - no else - should report error
}

int ArrayClass::get(int i) const
{
    if (i >= 0 && i < currentSize) {
        return arr[i];
    }
    // Returns 0 if i invalid - THIS IS NOT SATISFACTORY!
    else {
    	printf("ERROR: invalid index\n");
        return 0;
    }
}

int ArrayClass::capacity() const
{
    return arrSize;
}

int ArrayClass::size() const
{
    return currentSize;
}