#include <iostream>
using namespace std;
#include "PolyStack.h"

PolyStack::PolyStack()
{
    stack_top = nullptr;
    stack_size = 0;
}

bool PolyStack::empty()
{
    if (stack_size == 0)
        return true;
    else
        return false;
}

void PolyStack::push(Node* item)
{
    if (stack_top == nullptr)
        stack_top = item;
    else
    {
        item->next = stack_top;
        stack_top = item;
    }
    stack_size++;
}

Node* PolyStack::pop()
{
    if (!empty()) {
        Node* popped_node = stack_top;
        stack_size--;
        stack_top = stack_top->next;
        return popped_node;
    }
    else {
        cout << "The stack is empty\n";
        return nullptr;
    }
}

void PolyStack::display()
{
    if (!empty()) {
        Node* current;
        current = stack_top;
        cout << "\nStack Contents: \n";
        while (current != nullptr) {
            cout << current->coef << "x^" << current->exp << " ";
            current = current->next;
        }
    }
    else {
        cout << "The stack is empty \n";
    }
}