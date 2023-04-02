/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Implementation of Computer class
*/

#include "Computer.h"

Computer::Computer() {
    available = true;
}

bool Computer::isAvailable() const {
    return available;
}

void Computer::setAvailable(bool b) {
    available = b;
}

int Computer::getTime() const {
    return takeTime;
}

void Computer::setTime(int x) {
    takeTime = x;
}

int Computer::getBusyTime() const {
    return busyUntil;
}

void Computer::setBusyTime(int x) {
    busyUntil = x;
}
