#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main(void)
{       long int pht[1024]={0};
	long int array[1024]={0};
        unsigned int lht[128]={0};
	long int* phistory_Content = 0;
	long unsigned int ght = 0;
        unsigned int *lhtContent=0;
	long unsigned int address;
	char history;
	long unsigned int misses =0, hits = 0; 
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	long i=0, k=0;
	int counter;
	printf("Please Enter the counter: ");
	scanf("%d",&counter);
    fp = fopen("trace.trace", "r");
   
     int temp=1;
     int temp1=1;
    
    for(i=1;i<=counter;i++)
    {
     temp=2*temp;
    }
    for(i=1;i<=(counter-1);i++)
    {
     temp1=2*temp1;
    }
    
    
	
    while ((read = getline(&line, &len, fp)) != -1) {
		sscanf(line,"%lu %c",&address,&history);
       lhtContent = &lht[((address & 0x1FC) >> 2)];
        phistory_Content = &pht[(*lhtContent & 0x3FF)]; 
		if(history == 'N')
		{
			if(*phistory_Content == 0)
				hits++;
			else if(*phistory_Content >= 1 && *phistory_Content <=(temp1-1))
			{
				hits++;
				*phistory_Content -= 1;
			}
			else if(*phistory_Content >= temp1 && *phistory_Content <= temp-1)
			{
				misses++;
				*phistory_Content -= 1;
			}ght = (ght << 1);	
		}
		else if(history == 'T')
		{
			
			if(*phistory_Content == temp-1)
				hits++;
			else if(*phistory_Content >= temp1 && *phistory_Content <= temp-2)
			{
				hits++;
				*phistory_Content += 1;
			}
			else if(*phistory_Content >= 0 && *phistory_Content <= temp1-1)
			{
				misses++;
				*phistory_Content += 1;
			}ght = ((ght << 1) | 0x01);	
		}
		
    }
    printf("hits = %lu, misses = %lu\n", hits, misses);
   
    

}



