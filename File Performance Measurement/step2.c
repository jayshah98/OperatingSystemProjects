//Jay Shah
//03/10/2020
//Lab9: File Performance Measurement
//Step 2: read file with buffer size N as parameter  

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
     //   char newFileName[20]; 
//        sprintf(newFileName,"%S.copy",argv[1]); 
        int buf_size = atoi(argv[2]); 
	char buf[buf_size];
	FILE *rb = fopen(argv[1], "rb");  
        while(fgets(buf, buf_size, rb))
	fclose(rb);
}


