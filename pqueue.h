// File:       pqueue.h
#include "event.h"

typedef Event* PQItemType;
typedef double PQPriorityType;
typedef void (ItemPrinter)(const PQItemType&);
typedef void (PriorityPrinter)(PQPriorityType);

struct PQCell;

struct PriorityQueue
{
	PQCell* head;

	PriorityQueue()
	{
		//head = nullptr;
	}
};

bool isEmpty(const PriorityQueue& q);

void insert(PQItemType item, PQPriorityType pri, PriorityQueue& q);

void remove(PQItemType& item, PQPriorityType& pri, PriorityQueue& q);

void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp);
