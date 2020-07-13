//Jay Shah
//03/10/2020
//Lab9: File Performance Measurement
//Step 1: read file from beginning to end 


#include <stdio.h>
#include <stdlib.h> 
#define BUF_SIZE 10000
int main(int argc, char *argv[]) {  
	char buf[BUF_SIZE]; 
	FILE *rb = fopen(argv[1], "rb");  
	while(fgets(buf,BUF_SIZE,rb))   
	fclose(rb);
}


