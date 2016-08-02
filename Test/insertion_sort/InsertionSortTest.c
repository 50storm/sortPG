#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 1
 
long COMPARE_COUNT=0;


int Insertion_Sort(long X[], long num){
      int i,j,tmp;
      for(i=1; i < num ; i++)
      {
            tmp = X[i];
            for(j=i-1; j>=0 ; j--)
            {
                  COMPARE_COUNT++;
                  if(tmp < X[j])
                  {
                    X[j+1]=X[j];
                    if(j==0) X[0]=tmp;
                  }else{
                    X[j+1] = tmp;
                    break;
                  }
            }
      }
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
    filename = "before_insertion_sort" ;
    fp = fopen(filename, "w");
    for(i=0;i<size;i++)   fprintf( fp, "%ld\n",   Data[i]  );
    fclose(fp);
#endif
        
    /* Sort Data */
    COMPARE_COUNT=0;
    clock_t start, end;
    start = clock();
    Insertion_Sort(Data,size);
    end = clock();
    printf("=Insertion Sort=\t\tComparing: %ld\n" , COMPARE_COUNT);
    printf("time: %f[sec]\n", (double)(end - start) / CLOCKS_PER_SEC);

#if DEBUG==1
    /*Write data after sorting*/
    filename = "after_insertion_sort" ;
    fp = fopen(filename, "w");
    for(i=0;i<size;i++) fprintf( fp, "%ld\n",   Data[i]  );
    fclose(fp);
#endif
    /* free memory */
    free(Data); 
    return 0;


}
