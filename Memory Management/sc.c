//Jay Shah
//03/08/2020
//Lab 8: Memory Management
//Second Chance Page Replacement Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {//to
    int pageno;
    int chance;
} ref_page;


int main(int argc, char *argv[]){
    int pointer = 0;
    int C_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[C_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < C_SIZE; i++){//initialise cache array
        cache[i].pageno = -1;
	cache[i].chance = 0; 
    }
    int set=0;
    int j,hit,l;
    while (fgets(pageCache, 100, stdin)){
        int page_num = atoi(pageCache); // Stores number read from file as an int
     
        hit = 0;
        for(j=0; j<C_SIZE; j++){
            if(cache[j].pageno == page_num){
                hit = 1;
                cache[j].chance=1;
      	    }
        }
        if(hit==0 && set<C_SIZE){
            printf("Page %d caused a page fault.\n",page_num);
            cache[set].pageno = page_num;
            set++;
            totalFaults++;
//	    pointer = (pointer+1)%C_SIZE;
	}
        else if(hit==0 && set>=C_SIZE){
            printf("Page %d caused a page fault.\n",page_num);
	   l=pointer; 
	    while(cache[l].chance==1){
		cache[l].chance=0; 
		l++;
		if(l==C_SIZE) l=0; 
	    }
	    pointer=l;
//	    printf("break : %d\n", l); 
            cache[l].pageno = page_num;
            cache[l].chance = 0;
	    pointer = (pointer+1)%C_SIZE;
            totalFaults++;
        }
    }
    printf("%d Total Page Faults", totalFaults);
    printf("\n");
    printf("Page Fault Rate: %.3f", ((double)totalFaults/10000));
    printf("\n");
    printf("Hit Rate: %.3f", 1 -((double)totalFaults/10000));
    printf("\n");
    return 0;
}



