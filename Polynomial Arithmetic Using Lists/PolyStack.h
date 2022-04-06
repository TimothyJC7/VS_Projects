#pragma once
#include "Node.h"

class PolyStack
{
public:
    Node* stack_top;
    int stack_size;
    PolyStack();
    bool empty();
    void push(Node* item);
    Node* pop();
    void display();
};