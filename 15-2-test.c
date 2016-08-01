#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 10000

int COMPARE_COUNT=0;
int SWAP_COUNT=0;

int Swap(int i, int j, int x[])
{
    int tmp;
   
    tmp = x[i];
    x[i] = x[j];
    x[j] = tmp;
   
    SWAP_COUNT++;
    return 0;
}

int Partial_Insertion_Sort(int min, int max, int x[])
{
  //printf("Partial_Insertion_Sort\n");
    int i,j,tmp;
   
    for(i=min+1;i<=max;i++){
        tmp = x[i];
        for(j=i-1;j>=min;j--){
            COMPARE_COUNT++;
            if(x[j]>tmp){
                x[j+1]=x[j];
                if(j==min) x[min]=tmp;
            }else{
                x[j+1]=tmp;
                break;
            }
        }
    }
    return 0;
}


int Super_Quick_Sort(int change_num, int min, int max, int x[])
{
    int i,j,p;

    //if(min>=max)return 1;
    if( (max-min) <change_num)
    {
      Partial_Insertion_Sort( min, max,x);
      return 1;
    }

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
        Swap(i,j,x);
        i++; j--;
        }

    Super_Quick_Sort(change_num,min,i-1,x);
    Super_Quick_Sort(change_num,j+1,max,x);

    return 0;
}

int main()
{
    int     Data[DATA_SIZE];
    int     i,n,seed,change;

    printf("**************************************\n");
    printf("*                                    *\n");
    printf("*  Generating Random Data from Seed  *\n");
    printf("*                 and                *\n");
    printf("*  Changing Algorythm while Sorting  *\n");
    printf("*                                    *\n");
    printf("*            exit => input 0         *\n");
    printf("**************************************\n");


    while(1)
    {
       printf("\nSeed:");
       scanf("%d",&seed);
       if(seed<=0) return 1;
       printf("Change:");
       scanf("%d",&change);
       if(change<=0) return 1;
       
       /* Make Data */
       srand(seed);
       for(i=0;i<DATA_SIZE;i++) Data[i]=rand()%DATA_SIZE;

       /* Sort Data */
       COMPARE_COUNT=0;
       SWAP_COUNT=0;
       Super_Quick_Sort(change,0,DATA_SIZE-1,Data);
       printf("Seed:%d\tChange:%d\tCompare:%d\tSwap:%d\n"
             ,seed,change,COMPARE_COUNT,SWAP_COUNT);
      
    }
    return 0;
}

