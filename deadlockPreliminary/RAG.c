#include <stdlib.h>
#include <stdio.h>
#include "RAG.h"
/**
* Single nstance resource allocation graph (RAG)
* Implemented using matrix representation of the graph
*/
//Using a matrix so lookups/adds are O(1)
 //
//extern **matrix;
node matrix[SIZE][SIZE];

/*
void init(){
	
	**matrix = malloc(SIZE * sizeof *matrix + (SIZE * (SIZE * sizeof **array)));
	//int * const data = array + nrows;
	for(i = 0; i < SIZE; i++)
  		matrix[i] = data + i * ncolumns;

	int i, j;
	for(i=0; i<SIZE; i++){
		//malloc the columns
		matrix = (node*)malloc(sizeof(node));
		for(j=0;j<SIZE; j++){
			//Malloc the rows
			matrix[i] = (node*)malloc(sizeof(node));
		}
	}
}
*/
/*
 * Adds a request edge from pid to lockid
 * @param pid
 * @param lockid
 */
void rag_request(int pid, int lockid){
	    printf("In rag request\n");

	//Find the correct cell and initialize
	int cell = translateIndex(pid);
	matrix[cell][lockid].val = 1;
	matrix[cell][lockid].req = "R";
	matrix[cell][lockid].x = cell;
	matrix[cell][lockid].y = lockid;

}


void rag_alloc(int pid, int lockid){
	   printf("in alloc\n");

	//find the correct cell and update the matrix
	int cell = translateIndex(pid);
	matrix[lockid][cell].val =1;
	matrix[cell][lockid].val = 0;
}



void rag_dealloc(int pid, int lockid){
	   printf("in rag_dealloc\n");

	//Find the correct cell and then set its value to 0
	int cell = translateIndex(pid);
	matrix[lockid][cell].val = 0;
}


//Print the matrix
void rag_print(){
	    printf("in print\n");

	int i, j;
	for(i=0; i< SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("%d", matrix[i][j].val);
		}
		printf("\n"); //New line after each row
	}

}

//Clear up memory
/*
void freeMatrix(){
	int i, j;
	for(i=0; i<SIZE; i++){
		//malloc the columns
		for(j=0;j<SIZE; j++){
			//Malloc the rows
			free(matrix[i][j]);
		}
	}
}
*/

/**
 * Translate only for a thread node
 *
 */
int translateIndex(int v){
	//If it is a lock node it will occupy cells 0-9
	//If it is a thread node it will occupy cells 10-29
	return v + 10;

}


void deadlock_detect(void){
	    printf("In detect\n");

	int i, j;
	//Initialize all to be unvisited
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			matrix[i][j].color = WHITE;
		}
	}

	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(matrix[i][j].color == WHITE){
				if(deadlock_helper(&matrix[i][j]) == 0){
					//True?
					printf("DEADLOCK with vertex[%d][%d]\n", i, j);

				}
			}
		}
	}
	//False?

}


int deadlock_helper(node *v){
	   //printf("In helper\n");

	int i;
	v->color = GREY;
	//Iterate over 
	for(i=0; i<SIZE; i++){
		//Don't worry about non existant edges
		if(matrix[i][v->y].val != 1){
			continue;
		}else if(matrix[i][v->y].color == GREY){
			//Cycle occured
			//printf("DEADLOCK with vertex[%d][%d]\n", i, v->y);

			return 0; //TRUE
		}else if(matrix[i][v->y].color == WHITE){
			if(deadlock_helper(&matrix[i][v->y]) == 0){
				return 0; //TRUE
			}
		}
	}
	v->color = BLACK;
	return 1; //FALSE

}