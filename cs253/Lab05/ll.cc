#include "ll.h"
#include <iostream>
#include <cstdlib>

using namespace std;

LinkedList::LinkedList() : m_pHead(nullptr) {}

LinkedList::~LinkedList() {
    while (!m_pHead) {
        Link *temp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete temp;
    }
}

void LinkedList::Link::initialize(unsigned uiData, Link *pNext) {
    m_uiData = uiData;
    m_pNext = pNext; 
}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link;			// Get a new node.

    new_link->initialize(uiData, m_pHead); // Fill it with data.
    m_pHead = new_link;			// Put it at the head.

    return true;				// Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
    if (!m_pHead)				// Empty list?
	    return false;				// Indicate failure.

    Link *temp = m_pHead;			// Point to the first node
    m_pHead = m_pHead->m_pNext;	    // Remove the first node.
    pData = temp->m_uiData;			// Obtain first node’s data.
    delete temp;

    return true;				// Indicate success.
}

int LinkedList::print() {
    return print(cout);
}

int LinkedList::print(ostream &os) {
    if (!m_pHead)
        return -1;
    Link *loc = m_pHead;
    do {
	    os << loc->m_uiData << " ";
	    loc = loc->m_pNext;
    } while (loc != nullptr);
    os << "\n";
    return 0;
}

ostream &operator<<(ostream &os, LinkedList &l) { 
    l.print(os);
    return os;
}