/**
* Single nstance resource allocation graph (RAG)
* Implemented using matrix representation of the graph
*/
//Using a matrix so lookups/adds are O(1)
 //
extern *matrix;

void init(){
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
/*
 * Adds a request edge from pid to lockid
 * @param pid
 * @param lockid
 */
void rag_request(int pid, int lockid){
	int cell = translateIndex(pid);
	matrix[cell][lockid]->val = 1;
	matrix[cell][lockid]->req = "R";
	matrix[cell][lockid]->x = cell;
	matrix[cell][lockid]->y = lockid;

}


void rag_alloc(int pid, int lockid){
	int cell = translateIndex(pid);
	matrix[lockid][cell] = 1;
	matrix[cell][lockid] = 0;
}


void rag_dealloc(int pid, int lockid){
	int cell = translateIndex(pid);
	matrix[lockid][cell] = 0;
}


void rag_print(){
	int i, j;
	for(i=0; i< SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("%d", matrix[i][j]);
		}
		printf("\n"); //New line after each row
	}

}

//Clear up memory
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
	int i, j;
	//Initialize all to be unvisited
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			matrix[i][j]->color = WHITE;
		}
	}

	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			if(matrix[i][j] == WHITE){
				if(visit(matrix[i][j]) == 0){
					//True?
				}
			}
		}
	}
	//False?

}


int deadlock_helper(node *v){
	int i, j;
	v->color = GREY;
	//Iterate over 
	for(i=0; i<SIZE; i++){
		//Don't worry about non existant edges
		if(matrix[i][v->y] != 1){
			continue;
		}else if(matrix[i][v->y]->color == GREY){
			//Cycle occured
			printf("DEADLOCK with vertex[%d][%d]\n", i, v->y);
			return 0; //TRUE
		}else if(matrix[i][v->y]->color == WHITE){
			if(deadlock_helper(matrix[i][v->y]) == 0){
				return 0; //TRUE
			}
		}
	}
	v->color = BLACK;
	return 1; //FALSE

}