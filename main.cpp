/*
* Title: Heaps, Priority Queues
* Author: Berk Temel
* ID: 22002675
* Section: 2
* Assignment: 3
* Description: Simulations to find computer number occurs here
*/

#include <iostream>
#include "PriorityQueue.h"
#include <fstream>
#include "Computer.h"
#include <sstream>

bool getAvailableComputer(Computer c[], int size, int& index) {
    for(int i = 0; i < size; i++) {
        if(c[i].isAvailable()) {
            index = i;
            return true;
        }
    }
    return false;
}

void Simulation(PriorityQueue pq, int reqCount, int computerCount, double& simTime) {
    double avgTime;

    KeyedItem top;
    Computer computers[computerCount];
    double total = 0;

    for (int i = 0; i < 500; i++) {
        if (pq.pqIsEmpty())
            break;

        for (int j = 0; j < computerCount; j++) {
            if (computers[j].getBusyTime() == i)
                computers[j].setAvailable(true);
        }

        pq.pqChange(i);

        int compIndex;
        pq.pqPeek(top);

        while (getAvailableComputer(computers, computerCount, compIndex) && top.getSendTime() <= i) {
            if(pq.pqIsEmpty())
                break;
            pq.pqDelete(top);
            computers[compIndex].setTime(i);
            computers[compIndex].setAvailable(false);
            computers[compIndex].setBusyTime(i + top.getExecTime());
            int wait = i - top.getSendTime();
            total += wait;

            pq.pqPeek(top);
        }
    }
    avgTime = total / reqCount;

    simTime = avgTime;
}

void SimulationPrint(PriorityQueue pq, int reqCount, int computerCount) {
    cout << "Minimum number of computers required: " << computerCount << endl;
    cout << endl;
    cout << "Simulation with " << computerCount << " computers:" << endl;
    cout << endl;

    KeyedItem top;
    int compCount = computerCount;
    Computer computers[compCount];
    double avgWaitTime = 0;

    for(int i = 0; i < 500; i++) {
        if(pq.pqIsEmpty())
            break;

        for(int j = 0; j < compCount; j++) {
            if(computers[j].getBusyTime() == i)
                computers[j].setAvailable(true);
        }

        pq.pqChange(i);

        int compIndex;
        pq.pqPeek(top);

        while (getAvailableComputer(computers, compCount, compIndex) && top.getSendTime() <= i) {
            if(pq.pqIsEmpty())
                break;
            pq.pqDelete(top);
            computers[compIndex].setTime(i);
            computers[compIndex].setAvailable(false);
            computers[compIndex].setBusyTime(i + top.getExecTime());
            int wait = i - top.getSendTime();
            avgWaitTime += wait;

            cout << "Computer " << compIndex << " takes request " << top.getId() << " at ms "
                 << i << " (wait: " << wait << " ms)" << endl;
            pq.pqPeek(top);
        }
    }

    cout << endl;
    cout << "Average waiting time: " << avgWaitTime / reqCount << endl;
}

int main(int argCount, char** arguments) {
    ifstream file;
    file.open(arguments[1], ios::in);
    if(!file.is_open()) {
        cout << "File couldn't be opened.";
    }

    PriorityQueue pq;
    int number;
    int reqCount;
    file >> reqCount;

    int id;
    int priority;
    int sendTime;
    int execTime;
    int counter = 0;
    while (file >> number) {
        if(counter == 0)
            id = number;
        else if(counter == 1)
            priority = number;
        else if(counter == 2)
            sendTime = number;
        else if(counter == 3)
            execTime = number;
        counter++;

        if(counter == 4) {
            KeyedItem request(id,priority,sendTime,execTime);
            request.setCurrentTime(0);
            pq.pqInsert(request);
            counter = 0;
        }
    }

    int compCount = 0;
    PriorityQueue temp = pq;

    stringstream ss;
    ss << arguments[2];
    double maxTime;
    ss >> maxTime;

    double simTime = maxTime + 1;
    while (simTime > maxTime) {
        compCount++;
        Simulation(temp, reqCount, compCount, simTime);
    }
    SimulationPrint(pq, reqCount, compCount);

    file.close();

}
