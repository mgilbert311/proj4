/**
* Reads in the file and builds the RAG then checks for deadlock
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *matrix;

int main(int argc, char** argv){

    FILE *fp;
    char fileBuffer[10];
    char const t[2] = ","; //The delimiter
    int pid, lockid;
    char *token;
    if(argc != 2){
        printf("Usage: ./deadlock </path/to/input/file>\n");
        exit(1);
    }

    //TODO: Remove, just for testing
    printf("Input file %s\n",argv[1]);
    init()
    //Open the file
    fp = fopen(argv[1], "r");
    if(fp){

        while(fgets(fileBuffer, 10, fp) != NULL){
            pid = strtok(fileBuffer, t);
            token = strtok(fileBuffer, NULL);
            if(strcmp(token,"R")){
                //Must be an allocation 
               lockid = strtok(fileBuffer, NULL); 
                rag_request(pid, lockid);
            }else if(strcmp(token, "A")){
                lockid = strtok(fileBuffer, NULL); 
                rag_alloc(pid, lockid);
            }else if(strcmp(token, "D")){
                lockid = strtok(fileBuffer, NULL); 
                rag_dealloc(pid, lockid);
            }else{
                printf("That is not a valid code\n");
                exit(1);
            }
            //printf("Line: %s", fileBuffer);
        }

        fclose(fp);
    }
    else{
        printf("Error problem opening file\n");
        exit(1);
    }
    //Run the deadlock detection
    deadlock_detect(void);
    return 0;
}