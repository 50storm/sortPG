#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 10000
 
int COMPARE_COUNT=0;
 
int Swap( int x[], int i, int j)
{
   int tmp;
 
   tmp = x[i];
   x[i] = x[j];
   x[j] = tmp;
 
   return 0;
}
 
int Quick_Sort(int x[], int min, int max)
{
   int i,j,p;
 
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
 

int main()
{
    int Data[DATA_SIZE];
    int i,n,seed,change_num;

    printf("DATASIZE=%d\n",DATA_SIZE);

    while(1)
    {
        printf("Input seed (end=0) :");
        scanf("%d",&seed);        
        if(seed==0) return 0;
        
        /* Make Data */
        srand(seed);
        for(i=0;i<DATA_SIZE;i++) Data[i]=rand()%DATA_SIZE;
        
        fort(i=0; i<DATA_SIZE;i++){
            printf("Data=%d",Data[i]);
        }
        
        
        
        /* Sort Data */
        COMPARE_COUNT=0;
        Quick_Sort(Data,0,DATA_SIZE-1);
        printf("=Quick Sort=\t\tComparing: %d\n" , COMPARE_COUNT);

    }
    return 0;
}
