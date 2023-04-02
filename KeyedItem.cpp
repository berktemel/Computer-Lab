/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Implementation of KeyedItem class, this class is basically the requests, from lecture slides
*/
#include "KeyedItem.h"

KeyedItem::KeyedItem() {

}

KeyedItem::KeyedItem(int id, int priority, int sendTime, int execTime) {
    this->id = id;
    this->priority = priority;
    this->sendTime = sendTime;
    this->execTime = execTime;
}

int KeyedItem::getId() const {
    return id;
}

int KeyedItem::getPriority() const {
    return priority;
}

int KeyedItem::getSendTime() const {
    return sendTime;
}

int KeyedItem::getExecTime() const {
    return execTime;
}

bool KeyedItem::operator > (const KeyedItem &r) const {
    if(currentTime >= this->getSendTime() && currentTime >= r.getSendTime()) {
        if (this->getPriority() < r.getPriority())
            return false;
        else if (this->getPriority() > r.getPriority())
            return true;
        else
            return this->getId() < r.getId();//this->getSendTime() < r.getSendTime();
    } else {
        if (this->getSendTime() > r.getSendTime())
            return false;
        else if (this->getSendTime() < r.getSendTime())
            return true;
        else
            return this->getPriority() > r.getPriority();
    }
}

void KeyedItem::setCurrentTime(int t) {
    currentTime = t;
}

bool KeyedItem::operator < (const KeyedItem &r) const {
    if(currentTime >= this->getSendTime() && currentTime >= r.getSendTime()) {
        if (this->getPriority() < r.getPriority())
            return true;
        else if (this->getPriority() > r.getPriority())
            return false;
        else
            return this->getId() > r.getId();//this->getSendTime() < r.getSendTime();
    } else {
        if (this->getSendTime() > r.getSendTime())
            return true;
        else if (this->getSendTime() < r.getSendTime())
            return false;
        else
            return this->getPriority() < r.getPriority();
    }
}
