#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 1
 
long COMPARE_COUNT=0;
 
int Swap( long x[], long i, long j)
{
   long tmp;
 
   tmp = x[i];
   x[i] = x[j];
   x[j] = tmp;
 
   return 0;
}

int Quick_Sort(long x[], long min, long max)
{
   long i,j,p;
   if(min>=max)return 1;
 
   p = x[(min+max)/2];
   i = min;
   j = max;
 
   while(i<=j)
       {
       while(x[i]<p){ i++; COMPARE_COUNT++;}
       COMPARE_COUNT++;
       while(x[j]>p){ j--; COMPARE_COUNT++;}
       COMPARE_COUNT++;
       if(i>=j) break;
       Swap(x,i,j);
       i++; j--;
       }
 
   Quick_Sort(x,min,i-1);
   Quick_Sort(x,j+1,max);
 
   return 0;
}
 

int main(int argc, char *argv[])
{
    long *Data;
    long size;
    long i,j,n,seed;
    FILE *fp;
    char  *filename;
    
    if(argc != 2)
    {
        printf("Please Input like this.\n");
        printf("./a.out 10000\n");
        return 0;
    }
    
    if(argc <0){
        printf("Please Input more than 0\n");
        printf("\n");
        return 0;
        
    }
    
    
    /*  alocation  */
    char *ends;
    size = strtol(argv[1], &ends,10);
    
    Data = (long*)malloc(sizeof(long)* size);
    if (Data == NULL) {
        printf( "memory allocation error\n" );
        exit(EXIT_FAILURE);
    }
   
    /* Make Data */
    srand((unsigned int)time(NULL)); //Hiroshi seedの工夫
    for(i=0;i<size;i++) Data[i]=rand();
    
#if DEBUG == 1    
    /*Write data before sorting*/
    filename = "before_quick_sort" ;
    fp = fopen(filename, "w");
    for(i=0;i<size;i++)  fprintf( fp, "%ld\n",   Data[i]  );
    fclose(fp);
#endif
        
    /* Sort Data */
    COMPARE_COUNT=0;
    clock_t start, end;
    start = clock();
    Quick_Sort(Data,0,size-1);
    end = clock();
    printf("=Quick Sort=\t\tComparing: %ld\n" , COMPARE_COUNT);
    printf("time: %f[sec]\n", (double)(end - start) / CLOCKS_PER_SEC);

#if DEBUG == 1    
    /*Write data after sorting*/
    filename = "after_quick_sort" ;
    fp = fopen(filename, "w");
    for(i=0;i<size;i++)  fprintf( fp, "%ld\n",   Data[i]  );
    fclose(fp);
#endif

    /* free memory */
    free(Data); 
    return 0;
}
