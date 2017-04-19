#define NLOCK 10
#define NPROC 20

void rag_request(int pid, int lockid);
void rag_alloc(int pid, int lockid);
void rag_dealloc(int pid, int lockid);
void rag_print();
void deadlock_detect(void);