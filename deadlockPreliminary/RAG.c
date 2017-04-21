/**
* Single nstance resource allocation graph (RAG)
* Implemented using matrix representation of the graph
*/
//Using a matrix so lookups/adds are O(1)
int matrix[NLOCK+NPROC][NLOCK+NPROC];
//int *matrix;

/*
 * Adds a request edge from pid to lockid
 * @param pid
 * @param lockid
 */
void rag_request(int pid, int lockid){
	int cell = translateIndex(pid);
	matrix[cell][lockid] = 1;
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

/**
 * Translate only for a thread node
 *
 */
int translateIndex(int v){
	//If it is a lock node it will occupy cells 0-9
	//If it is a thread node it will occupy cells 10-29
	return v + 10;

}
/*
 * DFS with deadlock detection
 *
 */
void deadlock_detect(void){
	//Stack for DFS
	sNode **st = (sNode*)malloc(sizeof(sNode)); //Just size for 1
	push(st, )
	int i;
	//Initialize visited to 0
	for(i=0; i<SIZE; i++){
		visited[i] = 0;
	}

	visited[0] = 1; //Set first to visited
	for(i=0; i< SIZE; i++){
		if(!visited[i])
	}
}

int deadlock_helper(node *v){
	int *visited = (int*)malloc(sizeof(int)*SIZE);

}

/*
void DepthFirstSearch(int start){
		Stack<Integer> st = new Stack<Integer>();
		boolean[] visited = new boolean[V];
		st.push(start);
		visited[start] = true;
		while(!st.isEmpty()){
			int temp = st.pop();
			System.out.print(temp + " ");
			for(int vertex : adj[temp]){
				if(!visited[vertex]){
					st.push(vertex);
					visited[vertex] =true;
				}
			}
		}
	}
*/