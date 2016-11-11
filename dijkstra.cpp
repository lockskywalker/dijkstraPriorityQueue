

#include <cstdio>
#include <iostream>
#include "event.h"
#include "pqueue.h"
using namespace std;

int TraceLevel = 1;

struct Edge
{
	int vertex;
	PQPriorityType weight;
	Edge* next;

	Edge(int j, double w, Edge* n)
	{
		vertex = j;
		weight = w;
		next = n;
	}
	Edge()
	{
		vertex = 0;
		weight = 0;
		next = NULL;
	}
};

struct Vertex
{
	Edge* list;
	PQPriorityType distance;
	int previous;

	Vertex()
	{
		list = NULL;
		distance = -1;
		previous = 0;
	}
};

struct Graph
{
	int numVerticies;
	int numEdges;
	Vertex* vInfo;

	Graph(int v)
	{
		numVerticies = v;
		numEdges = 0;
		vInfo = new Vertex[v+1];
	}
};

//Takes in input of the first vertex, the second vertex, and the weight.

void input(Graph* g)
{
	
	PQPriorityType weight;
	int v1, v2;
	while (true)
	{
		cin >> v1;
		if (v1 == 0)
		{
			break;
		}
		cin >> v2;
		cin >> weight;
		if (g->vInfo[v1].list == NULL)
		{
			Edge* tempList = new Edge(v2, weight, NULL);
			g->vInfo[v1].list = tempList;
		}
		else
		{
			Edge* tempList = new Edge(v2, weight, g->vInfo[v1].list);
			g->vInfo[v1].list = tempList;
		}
		if (g->vInfo[v2].list == NULL)
		{
			Edge* tempList = new Edge(v1, weight, NULL);
			g->vInfo[v2].list = tempList;
		}
		else
		{
			Edge* tempList = new Edge(v1, weight, g->vInfo[v2].list);
			g->vInfo[v2].list = tempList;
		}
	}
}

//Prints the values of Graph g.

void printGraph(Graph* g)
{
	Graph* temp = g;
	int i = 0;
	cout << "There are " << temp->numVerticies << " vertices." << endl;
	cout << "The edges are as follows." << endl <<endl;
	while (i < temp->numVerticies)
	{
		if (temp->vInfo[i].list == NULL)
		{
			i++;
		}
		else 
		{
			if (i < temp->vInfo[i].list->vertex)
			{
				cout << "(" << i << ",";
				cout << temp->vInfo[i].list->vertex << ") ";
				cout << "weight " << temp->vInfo[i].list->weight << endl;
			}
			temp->vInfo[i].list = temp->vInfo[i].list->next;
		}
	}
}

//Creates new events from an adjacenecy list and then inserts the events into PriorityQueue queue.

void createEvents(PriorityQueue& queue, Edge* list, PQItemType temp)
{
	if (list != NULL)
	{
		if (TraceLevel == 1)
		{
			cout << "Signal is being sent from " << temp->receiver << " to " << list->vertex << " at time " << temp->time << "." << endl << "Arriving at " << list->weight + temp->time << endl;
		}
		Event* e = new Event(temp->receiver, list->vertex, list->weight + temp->time);
		insert(e, temp->time, queue);
		createEvents(queue, list->next, temp);
	}
}

//Takes the event queue and finds the shortest path from a start node to an end node

void dijkstra(Graph* g, int f, int l, PriorityQueue queue)
{
	Event* firstEvent = new Event(0, f, 0.0);
	insert(firstEvent, 0.0, queue);

	g->vInfo[0].distance = 0;
	g->vInfo[f].distance = 0;
	bool vst[g->numVerticies+1];

	for(int i=0;i<g->numVerticies+1;i++)	vst[i] = false;
	vst[f] = true;
	Edge* firstlist = g->vInfo[f].list;
	flist(Edge* firstlist);
	/*while(firstlist){
		g->vInfo[firstlist->vertex].distance = firstlist->weight;
		g->vInfo[firstlist->vertex].previous = f;
		firstlist = firstlist->next;
	}*/

	for(int i=0; i < g->numVerticies-1; i++){
		PQItemType temp1;
		PQPriorityType temp2, mind=1000000;

		int x;

		for(int j=1;j <= g->numVerticies;j++){
			if(vst[j]==false){
				if(g->vInfo[j].distance!=-1){
					if(g->vInfo[j].distance <= mind){
						mind = g->vInfo[j].distance;
						x = j;
					}
				}
			}
		}

		vst[x]=true;
		Edge* temp = g->vInfo[x].list;

		while(temp){
			if(g->vInfo[temp->vertex].distance==-1){
				g->vInfo[temp->vertex].distance = g->vInfo[x].distance + temp->weight;
				g->vInfo[temp->vertex].previous = x;
			}
			else{
				if(g->vInfo[temp->vertex].distance > g->vInfo[x].distance + temp->weight){
					g->vInfo[temp->vertex].distance = g->vInfo[x].distance + temp->weight;
					g->vInfo[temp->vertex].previous = x;
				}
			}
			temp = temp->next;
		}
	}
	//tracer(temp1, temp2, queue, distance,);
}

Edge flist(firstlist){

	while(firstlist){
		g->vInfo[firstlist->vertex].distance = firstlist->weight;
		g->vInfo[firstlist->vertex].previous = f;
		firstlist = firstlist->next;
	}

	return fristlist;
}

/*void tracer(Graph* g, int f, int l, PriorityQueue queue)
{
		/*PQItemType temp1;
		temp1->sender = f;
		createEvents(queue, g->vInfo[x].list, temp1);

   while (!isEmpty(queue))
	{
		PQItemType temp1;
		PQPriorityType temp2;
		remove(temp1, temp2, queue);
		createEvents(queue, g->vInfo[temp1->receiver].list, temp1);
		if (temp1->time > -1)
		{
			if (TraceLevel == 1)
			{
				cout << "The signal arrives at " << temp1->receiver << " from " << temp1->sender << " at time " << temp1->time << endl << endl;
			}
			g->vInfo[temp1->receiver].distance = temp1->time;
			g->vInfo[temp1->receiver].previous = temp1->sender;
		}
		if (g->vInfo[l].distance != -1)
		{
			cout << "BREAK" << endl;
			break;
		}
	}
}*/

int main(int argc, char** argv)
{
	int numVertices, x, first, last;
	PriorityQueue queue;
	queue.head = NULL;
	x = 0;
	cin >> numVertices;
	Graph* g = new Graph(numVertices);
	input(g);
	cin >> first;
	cin >> last;
	dijkstra(g, first, last, queue);
	printGraph(g);
	cout << "The shortest path sender " << first << " receiver " << last << " is " << g->vInfo[last].distance << endl;
	//printFinalPath(g, first, last);
	return 0;
}
