/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Header of KeyedItem class, from lecture slides
*/

#ifndef HW3_KEYEDITEM_H
#define HW3_KEYEDITEM_H

class KeyedItem {
public:
    KeyedItem();
    KeyedItem(int id, int priority, int sendTime, int execTime);

    int getId() const;
    int getPriority() const;
    int getSendTime() const;
    int getExecTime() const;
    bool operator > (const KeyedItem& r) const;
    bool operator < (const KeyedItem& r) const;
    void setCurrentTime(int t);

private:
    int id;
    int priority;
    int sendTime;
    int execTime;
    int currentTime;
};



#endif //HW3_KEYEDITEM_H
