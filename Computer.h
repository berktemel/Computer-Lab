/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Header for Computer class
*/

#ifndef HW3_COMPUTER_H
#define HW3_COMPUTER_H


class Computer {
public:
    Computer();
    bool isAvailable() const;
    void setAvailable(bool b);
    int getTime() const;
    void setTime(int x);
    int getBusyTime() const;
    void setBusyTime(int x);
private:
    bool available;
    int takeTime;
    int busyUntil;
};


#endif //HW3_COMPUTER_H
