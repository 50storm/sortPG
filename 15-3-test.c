#include<stdio.h>

int Swap(int X[], int i, int j)
{
    int tmp;
   
    tmp = X[i];
    X[i] = X[j];
    X[j] = tmp;
   
    return 0;
}

int Quick_Sort_Ex(int Data[],int min,int max,int Index[])
{
    int i,j,k,p;

    if(min>=max)return 1;

    p = Data[Index[(min+max)/2]];
    i = min;
    j = max;

    while(i<=j)
        {
        while(Data[Index[i]]<p) i++;
        while(Data[Index[j]]>p) j--;
        if(i>=j) break;
        Swap(Index,i,j);
        i++; j--;
        }
    Quick_Sort_Ex(Data,min,i-1,Index);
    Quick_Sort_Ex(Data,j+1,max,Index);

    return 0;
}

int main()
{
	int  Data[5]={51,19,34,92,73};
	int  Index[5]={0,1,2,3,4};
	int  i;

    /* Sort Data */  
    Quick_Sort_Ex(Data,0,4,Index);

    for(i=0;i<5;i++) printf("%d\t", Data[Index[i]] );
    printf("\n");

    return 0;
}
