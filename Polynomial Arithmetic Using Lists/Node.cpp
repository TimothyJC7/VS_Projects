#include <iostream>
using namespace std;
#include "Node.h"

Node::Node(int c, int e)
{
    coef = c;
    exp = e;
    next = nullptr;
}