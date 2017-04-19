/**
* Reads in the file and builds the RAG then checks for deadlock
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    if(argc != 2){
        printf("Usage: ./deadlock </path/to/input/file>\n");
        exit(1);
    }

    //TODO: Remove, just for testing
    printf("Input file %s\n",argv[1]);

    

    return 0;
}