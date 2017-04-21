#include <string.h>
#include <stdio.h>
#include "stack.h"

/*
 * Pushes the value to the top of the stack and reallocates the other elements
 * @param head the head of the list
 * @param val the value to be added
 */
void push(sNode **head, double value){
	sNode *temp; //Create a temp node
	temp = malloc(sizeof(sNode)); //Allocate the space
	//Assign the value
	temp->val = value;
	//Assign next to the previous head
	temp->next = *head;
	//Head of the stack is now the new node
	*head = temp;
}

/*
 * Returns the value of the top element
 * @param head the head of the stack
 */
double pop(sNode **head){
	double returnVal;
	sNode *temp = NULL;
	//If the stack is empty
	if(*head == NULL){
		return -1;
	}
	temp = (*head)->next;
	returnVal = (*head)->val;
	//Reclaim the used space
	free(*head);
	*head = temp;
	return returnVal;
}

/*
 * Returns the size of the stack
 * @param head the pointer to the head of the stack
 * @return counter the current size of the stack
 */
int size(sNode *head){
	//printf("In the size \n");
	sNode *temp = head;
	int counter = 0;
	//Iterate through the nodes and increment the counter
	while(temp != NULL){
		counter++;
		temp = temp->next;
	}	
	return counter;
}

/*
 * Helper method to examine the contents of the stack
 * @param head the pointer to the head of the stack
 */
void printList(sNode *head){
	sNode *temp = head;
	//Iterate through the stack
	while(temp != NULL){
		printf("This is printlist val %f \n", temp->val);
		temp = temp->next;
	}
}
