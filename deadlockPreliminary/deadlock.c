/**
* Reads in the file and builds the RAG then checks for deadlock
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    FILE *fp;
    char fileBuffer[10];

    if(argc != 2){
        printf("Usage: ./deadlock </path/to/input/file>\n");
        exit(1);
    }

    //TODO: Remove, just for testing
    printf("Input file %s\n",argv[1]);

    //Open the file
    fp = fopen(argv[1], "r");
    if(fp){

        while(fgets(fileBuffer, 10, fp) != NULL){

        printf("Line: %s", fileBuffer);
        }

        fclose(fp);
    }
    else{
        printf("Error problem opening file\n");
        exit(1);
    }

    return 0;
}