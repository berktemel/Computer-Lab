/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Implementation of Heap class, from lecture slides
*/
#include "Heap.h"

Heap::Heap() {
    size = 0;
}

bool Heap::heapIsEmpty() const {
    return size == 0;
}

void Heap::heapInsert(const KeyedItem &newItem) {
    if (size >= MAX_HEAP)
        return;
    items[size] = newItem;
    size++;
    heapRebuild(0);
}

void Heap::heapDelete(KeyedItem &rootItem) {
    if (heapIsEmpty())
        return;
    else {
        rootItem = items[0];
        items[0] = items[size - 1];
        size--;
        heapRebuild(0);
    }
}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1; 	// index of root's left child, if any
    if ( child < size ) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) &&
            (items[rightChild] > items[child]))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[root] < items[child]) {
            KeyedItem temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

bool Heap::heapFull() const {
    return size >= MAX_HEAP;
}

void Heap::heapPeek(KeyedItem &topItem) {
    topItem = items[0];
}

void Heap::heapChange(int time) {
    for(int i = 0; i < size; i++) {
        items[i].setCurrentTime(time);
    }
    heapRebuild(0);
}
