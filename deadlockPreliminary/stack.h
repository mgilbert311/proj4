#include <stdlib.h>

typedef struct node{
	double val;
	struct node *next;
} sNode;

void push(sNode **head, double value);
double pop(sNode **head);
int size(sNode *head);
void printList(sNode *head);
