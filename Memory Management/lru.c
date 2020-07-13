//Jay Shah
//03/08/2020
//Lab 8: Memory Management
//LRU Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct {//to
    int pageno;
} ref_page;

int main(int argc, char *argv[]){
    int C_SIZE = atoi(argv[1]); // Size of C_SIZE passed by user
    ref_page cache[C_SIZE]; // C_SIZE that stores pages
    char pageCache[100]; // C_SIZE that holds the input from test file
    
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    
    for (i = 0; i < C_SIZE; i++)//initialise C_SIZE array
        cache[i].pageno = -1;

    while (fgets(pageCache, 20, stdin)){
        int page_num = atoi(pageCache); // Stores number read from file as an int
// Stores number read from file as an int
    
    
        int track[C_SIZE];
        for(i=0;i<C_SIZE;i++)
        {
            track[i]=0;
        }//Track when the page is last used
        i=0;
        while(i<20){
            int j=0;
            int flag=0;
            while(j<C_SIZE){
                if(pageCache[i]==cache[j].pageno){
                    flag=1;
                    track[j]=i+1;
                }
                j++;
            }
            j=0;
            if(flag==0) {
                int min=0;
                int k=0;
                while(k<C_SIZE-1){
                    if(track[min]>track[k+1])
                        min=k+1;
                    k++;
                }
                printf("Page fault at %d\n", pageCache[i]);
                cache[min].pageno=pageCache[i];
                track[min]=i+1;
                totalFaults++;
            }
            i++;
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

