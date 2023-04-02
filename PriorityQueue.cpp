/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Implementation of PriorityQueue class, from lecture slides
*/

#include "PriorityQueue.h"

bool PriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const KeyedItem &newItem) {
    if(h.heapFull())
        cout << "Priority Queue is full" << endl;
    else
        h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(KeyedItem &priorityItem) {
    if(h.heapIsEmpty())
        cout << "Priority Queue is empty" << endl;
    else
        h.heapDelete(priorityItem);
}

void PriorityQueue::pqPeek(KeyedItem &topItem) {
    h.heapPeek(topItem);
}

void PriorityQueue::pqChange(int time) {
    h.heapChange(time);
}



