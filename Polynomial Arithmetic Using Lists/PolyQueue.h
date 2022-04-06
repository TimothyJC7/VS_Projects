#pragma once
#include "Node.h"

class PolyQueue {
    Node* qfront;
    Node* qback;
    int queueSize;
public:
    PolyQueue();
    bool empty();
    void enqueue(Node* newNode);
    Node* dequeue();
    Node* front();
    void display();
    int getSize();
};