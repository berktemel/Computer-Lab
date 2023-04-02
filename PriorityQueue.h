/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Header of PriorityQueue class, from lecture slides
*/

#ifndef HW3_PRIORITYQUEUE_H
#define HW3_PRIORITYQUEUE_H


#include "Heap.h"// ADT heap operations

class PriorityQueue {
public:
    // default constructor, copy constructor, and destructor
    // are supplied by the compiler

    // priority-queue operations:
    bool pqIsEmpty() const;
    void pqInsert(const KeyedItem& newItem);
    void pqDelete(KeyedItem& priorityItem);
    void pqPeek(KeyedItem& topItem);
    void pqChange(int time);

private:
    Heap h;
};


#endif //HW3_PRIORITYQUEUE_H
