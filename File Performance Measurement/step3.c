//Jay Shah
//03/10/2020
//Lab9: File Performance Measurement
//Step 2: read file with buffer size N as parameter  

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int BUF_SIZE = atoi(argv[2]);
	int buf[BUF_SIZE]; 
        char newFileName[20];
        sprintf(newFileName,"%s.copy",argv[1]);
        FILE *rb = fopen(argv[1], "rb");
        FILE *wb = fopen(newFileName, "wb");
        while(fread(buf,BUF_SIZE,1,rb))
                fwrite(buf,BUF_SIZE,1,wb);
      	fclose(rb); 
	fclose(wb);

}

