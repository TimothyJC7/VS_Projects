#include <iostream>
using namespace std;
#include "PolyQueue.h"

PolyQueue::PolyQueue() {
	qfront = nullptr;
	qback = nullptr;
	queueSize = 0;
}

bool PolyQueue::empty() {
	if ((qfront == nullptr) && (qback == nullptr))
		return true;
	else
		return false;
}

void PolyQueue::enqueue(Node* newnode) {
	if (empty()) {
		qback = newnode;
		qfront = qback;
	}
	else {
		qback->next = newnode;
		qback = newnode;
	}
	queueSize++;
}

Node* PolyQueue::dequeue() {
	Node* temp = nullptr;
	temp = front();
	qfront = qfront->next;
	queueSize--;
	return temp;
}

Node* PolyQueue::front() {
	return qfront;
}

void PolyQueue::display() {
	Node* current;
	current = qfront;
	if (qfront == nullptr)
		cout << "The Queue is Empty\n";
	else {
		while (current != nullptr) {
			cout << current->coef << "x^" << current->exp << " ";
			current = current->next;
		}
		cout << "\n";
	}
}

int PolyQueue::getSize() {
	return queueSize;
}