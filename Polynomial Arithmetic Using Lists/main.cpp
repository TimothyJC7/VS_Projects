#include <iostream>
using namespace std;
#include "Node.h"
#include "PolyQueue.h"
#include "PolyStack.h"

int main()
{
	PolyQueue polyQ1;
	PolyQueue polyQ2;

	// Declaring Polynomial p1
	Node* p11 = new Node(5, 0);
	Node* p12 = new Node(4, 5);
	Node* p13 = new Node(3, 13);
	Node* p14 = new Node(2, 27);
	Node* p15 = new Node(1, 49);

	polyQ1.enqueue(p11);
	polyQ1.enqueue(p12);
	polyQ1.enqueue(p13);
	polyQ1.enqueue(p14);
	polyQ1.enqueue(p15);
	cout << "Polynomial 1:\n";
	polyQ1.display();
	
	// Declaring Polynomial p2
	Node* p21 = new Node(8, 0);
	Node* p22 = new Node(13, 4);
	Node* p23 = new Node(21, 5);
	Node* p24 = new Node(34, 12);
	Node* p25 = new Node(55, 27);

	polyQ2.enqueue(p21);
	polyQ2.enqueue(p22);
	polyQ2.enqueue(p23);
	polyQ2.enqueue(p24);
	polyQ2.enqueue(p25);

	cout << "\nPolynomial 2:\n";
	polyQ2.display();

	// Add Polynomials and Store in stack
	PolyStack pStack;
	Node* p1term = nullptr;
	Node* p2term = nullptr;
	Node* psum = nullptr;


	while ((polyQ1.getSize() != 0) && (polyQ1.getSize() != 0)) {
		p1term = polyQ1.front();
		p2term = polyQ2.front();
		if (p1term == nullptr) {
			psum = new Node(p2term->coef, p2term->exp);
			pStack.push(psum);
			break;
		}
		else if (p2term == nullptr) {
			psum = new Node(p1term->coef, p1term->exp);
			pStack.push(psum);
			break;
		}
		else {
			if (p1term->exp == p2term->exp) {
				psum = new Node(p1term->coef + p2term->coef, p1term->exp);
				pStack.push(psum);
				polyQ2.dequeue();
				polyQ1.dequeue();
			}
			else if (p1term->exp > p2term->exp) {
				psum = new Node(p2term->coef, p2term->exp);
				pStack.push(psum);
				polyQ2.dequeue();
			}
			else {
				psum = new Node(p1term->coef, p1term->exp);
				pStack.push(psum);
				polyQ1.dequeue();
			}
		}
	}

	//Display Stack
	pStack.display();
	cout << "\n\n";

	return 0;
}


