#define NLOCK 10
#define NPROC 20
#define SIZE NLOCK + NPROC
//#define *matrix //The adjacency matrix
//For cycle detection
#define WHITE 0
#define GREY 1
#define BLACK 2
#define LOCK 0
#define THREAD 1

typedef struct node{
	int color; //The color of the node for the cycle detection
	int nodeType; //0-> lock, 1->thread (might not need)
	int loc; //The cell for visiting
} node;

typedef struct stack{
	node *head;
} stack;

void rag_request(int pid, int lockid);
void rag_alloc(int pid, int lockid);
void rag_dealloc(int pid, int lockid);
void rag_print();
int translateIndex(int v);
void deadlock_detect(void);
int deadlock_helper(node *v);