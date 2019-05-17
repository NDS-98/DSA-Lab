
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "graph.h"
#include "extras.h"


Graph initGraph(int N)
{
    int i;
    Graph g;
    g = (Graph) malloc(sizeof(struct _Graph));
    assert(g != NULL); // Assumptions made using assert function

    g->list = (node) malloc(sizeof(struct _node) * N);
    assert(g->list != NULL);

    g->visited = (bool*) malloc(sizeof(bool) * N);
    assert(g->visited != NULL);

    g->wt = (int*) malloc(sizeof(int) * N);
    assert(g->wt != NULL);

    g->vcount = N;
    g->ecount = 0;

    for(i = 0; i < N; i++)
    {
        g->list[i].id = i;
        g->list[i].next = NULL;
        g->visited[i] = false;
        g->wt[i] = -1;
    }
    return g;
}
void printAdjacencyList(Graph g)
{
	printf("Adjacency List:\n");
	for(int i=0;i<g->vcount;i++){
		node temp = &(g->list[i]);
		printf("%u \t ==> ",temp->id);
		
		temp = temp->next;
				
		while(temp!=NULL){
			printf("%u ",temp->id);
			temp = temp->next;			
		}
		printf("\n");
	}
}

/*
void insertNeighbor(node u, int v)
{
    node vnode = (node) malloc(sizeof(struct _node));
    assert(vnode != NULL);
    vnode->id = v;
    vnode->next = u->next;
    u->next = vnode;
}*/

void insertEdge(Graph g, unsigned int u, unsigned int v)
{
    //insertNeighbor(&(g->list[u]), v);
    node t = &(g->list[u]);
    node vnode = (node) malloc(sizeof(struct _node));
    assert(vnode != NULL);
    vnode->id = v;
    vnode->next = t->next;
    t->next = vnode;
    g->ecount++;
}
void bestFirstTraverse(Graph g)
{
	pq PriorityQ = createPQ();
	
	node temp = &(g->list[0]);
	printf("%u ",temp->id);
	g->visited[temp->id] = true;
	
	temp = temp->next;
	while(temp!=NULL){
		enqueue(&PriorityQ,temp,g->wt[temp->id]);
		g->visited[temp->id] = true;
		temp = temp->next;
	}
	
	while(!isEmpty(PriorityQ)){
		temp = dequeue(&PriorityQ);
		printf("%u ",temp->id);
		
		temp = &(g->list[temp->id]);
		temp = temp->next;
		
		while(temp!=NULL){
			if(!g->visited[temp->id]){
				enqueue(&PriorityQ,temp,g->wt[temp->id]);
				g->visited[temp->id] = true;
			}
			temp = temp->next;
		}
	}
}
