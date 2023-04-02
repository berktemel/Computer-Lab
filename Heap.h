/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Header of Heap class, from lecture slides
*/
#ifndef HW3_HEAP_H
#define HW3_HEAP_H

#include "KeyedItem.h"
#include <string>
#include <iostream>
using namespace std;

const int MAX_HEAP = 10000;

class Heap {
public:
    Heap();				// default constructor
                        // copy constructor and destructor are supplied by the compiler

    bool heapIsEmpty() const;
    void heapInsert(const KeyedItem& newItem);
    void heapDelete(KeyedItem& rootItem);

    bool heapFull() const;
    void heapPeek(KeyedItem& topItem);
    void heapChange(int time);

protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
                                    // index root into a heap
private:
    KeyedItem items[MAX_HEAP];	// array of heap items
    int size;            	// number of heap items
};



#endif //HW3_HEAP_H
