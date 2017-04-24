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

//Macro to help with DFS
#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

typedef struct node{
	int val;
	int color; //The color of the node for the cycle detection
	int nodeType; //0-> lock, 1->thread (might not need)
	int visited; //0 not visited, 1 visited
	int x;		//X coordinate
	int y;		//Y coordinate
	char *req;	//Which request value it is
	struct node *parent;
	//node *next; //Each list is a linked list
	//node *prev; //Needed for removing
	//int loc; //The cell for visiting
} node;



void rag_request(int pid, int lockid);
void rag_alloc(int pid, int lockid);
void rag_dealloc(int pid, int lockid);
void rag_print();
int translateIndex(int v);
void deadlock_detect(void);
int deadlock_helper(node *v);
void print_parent(node *v);
