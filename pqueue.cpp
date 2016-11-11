// CSCI 2530
// Assignment: 5
// Author:     Nigel Smtih
// File:       pqueue.cpp
// Tab stops:  2

/***************************************************
*                  pqueue.cpp                       *
****************************************************
* This program checks if a priority queue is empty,
* allows items to be inserted and removed from the
* pq. 
****************************************************/

#include<cstdio>
#include <cstddef>
#include "pqueue.h"
using namespace std;
struct PQCell {
	PQItemType item;
	PQPriorityType pri;
	struct PQCell* next;
};

/***************************************************
*                  isEmpty()                       *
****************************************************
* is Empty(PriorityQueue& q) returns a boolean 
* value based on if the queue is empty.
****************************************************/
bool isEmpty(const PriorityQueue& q) {
	return q.head == NULL;
}

/***************************************************
*            insert() and InsertCell()             *
****************************************************
* insert(PQItemType item, PQPriorityType pri,      *
* PriorityQueue& q) and insertCell(const           *
* PQItemType& item, PQPriorityType pri, PQCell*& p)*
* work to insert a new cell into the Priority Queue*
****************************************************/
void insertCell(const PQItemType& item, PQPriorityType pri, PQCell*& p) {
	if (p == NULL) {
		p = new PQCell();
		p->item = item;
		p->pri = pri;
		p->next = NULL;
	}
	else if (pri < (p->pri)) {
		PQCell* newCell = new PQCell();
		newCell->item = item;
		newCell->pri = pri;
		newCell->next = p;
		p = newCell;
	}
	else {
		insertCell(item, pri, p->next);
	}
}
void insert(PQItemType item, PQPriorityType pri, PriorityQueue& q) {
	insertCell(item, pri, q.head);
}

/***************************************************
*                   remove()                       *
****************************************************
* remove(PQItemType& item, PQPriorityType& pri, 
* PriorityQueue& q) removes the cell from the
* priority queue.
****************************************************/
void remove(PQItemType& item, PQPriorityType& pri, PriorityQueue& q) {
	//item = (q.head)->item;
	//pri = (q.head)->pri;
	//q.head = (q.head)->next;
    item = q.head->item;
		pri = q.head->pri;
		PriorityQueue priQTemp;
		priQTemp.head = q.head;
		q.head = priQTemp.head->next;
		delete priQTemp.head;	
}

/***************************************************
*             printPriorityQueue()                 *
****************************************************
* printPriorityQueue(const PriorityQueue& q, 
* ItemPrinter pi, PriorityPrinter pp) prints out
* the Priority Queue in order. 
****************************************************/
void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp)
{
	PriorityQueue temp;
	temp.head = q.head;
	while (temp.head != NULL)
	{
		pi(temp.head->item);
		printf("\t");
		pp(temp.head->pri);
		printf("\n");
		temp.head = temp.head->next;
	}
}
