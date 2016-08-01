#include<stdio.h>
#define DATA_SIZE 100

int Swap(int X[], int i, int j)
{
    int tmp;
   
    tmp = X[i];
    X[i] = X[j];
    X[j] = tmp;
   
    return 0;
}

int Quick_Sort_Ex(int Data[], int min, int max, int Index[])
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

int Binary_Search_Ex( int Data[],int num,int y,int Index[])
{
    int min,mid,max;

    min = 0;
    max = num-1;
    while(min<=max){
        mid = (min + max)/2;
        if(Data[Index[mid]]==y) return mid;
        else if(Data[Index[mid]]<y) min = mid + 1;
        else if(Data[Index[mid]]>y) max = mid - 1;
    }
    return -1;
}

int Linear_Search(int X[], int n, int y)
{
    int i;
   
    i=0;
    while(i<n){
        if(X[i]==y) return i;
        else i++;
    }
    return -1;
}


int main()
{
    char  filename[20];
    FILE  *fp;

    int  Data[3][DATA_SIZE];
    int  Index0[DATA_SIZE],Index1[DATA_SIZE],Index2[DATA_SIZE];
    int  i,num,rc,id,elem,rank0,rank1,rank2;
 
    /* Get FileName */
    printf("Input filename : ");
    scanf("%s", filename);

    /* Read File */
    fp=fopen(filename, "r");
    if(fp==NULL) return -1;
    num=0;
    while(num<DATA_SIZE)
        {
        rc=fscanf(fp,"%d%d%d",&Data[0][num],&Data[1][num],&Data[2][num]);
        if(rc == EOF)break;
        num++;
        }
    fclose(fp);

    /* Sort Id */ 
    for(i=0;i<num;i++) Index0[i] = i;
    Quick_Sort_Ex(Data[0],0,num-1,Index0);

    /* Sort English */ 
    for(i=0;i<num;i++) Index1[i] = i;
    Quick_Sort_Ex(Data[1],0,num-1,Index1);

    /* Sort Math */  
    for(i=0;i<num;i++) Index2[i] = i;
    Quick_Sort_Ex(Data[2],0,num-1,Index2);

    while(1)
    {
        /* Search ID */
        printf("Input ID : ");
        scanf("%d",&id);
        if(id==0) return 0;

        rank0 = Binary_Search_Ex(Data[0],num,id,Index0);
        if(rank0 == -1) return 1;
        elem = Index0[rank0];
        printf("Score: English=%d\tMath=%d\n",Data[1][elem],Data[2][elem]);

        rank1 = Binary_Search_Ex(Data[1],num,Data[1][elem],Index1 );
        rank2 = Binary_Search_Ex(Data[2],num,Data[2][elem],Index2 );
        printf("Rank:  English=%d\tMath=%d\n",num-rank1,num-rank2);
    }
    return 0;
}
